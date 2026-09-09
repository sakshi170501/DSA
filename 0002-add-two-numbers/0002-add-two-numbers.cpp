class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res = NULL;
        ListNode* curr = NULL;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            if (res == NULL) {
                res = newNode;
                curr = newNode;
            }
            else {
                curr->next = newNode;
                curr = curr->next;
            }
        }

        return res;
    }
};