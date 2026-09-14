/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* curr = head->next;
        ListNode* write = head;

        int sum = 0;

        while (curr != NULL) {

            if (curr->val == 0) {
                write = write->next;
                write->val = sum;
                sum = 0;
            } 
            else {
                sum += curr->val;
            }

            curr = curr->next;
        }

        write->next = NULL;

        return head->next;
    }
};