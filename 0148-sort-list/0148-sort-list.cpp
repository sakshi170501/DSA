class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != NULL) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* right = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge both sorted halves
        return merge(left, right);
    }
};