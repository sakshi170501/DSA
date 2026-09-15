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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* temp = head;

        // Find kth node from beginning
        for(int i = 1; i < k; i++) {
            temp = temp->next;
        }

        ListNode* first = temp;

        // Find length of linked list
        int length = 0;
        temp = head;

        while(temp != NULL) {
            length++;
            temp = temp->next;
        }

        // Find kth node from end
        temp = head;

        for(int i = 1; i < length - k + 1; i++) {
            temp = temp->next;
        }

        ListNode* second = temp;

        // Swap values
        swap(first->val, second->val);

        return head;
    }
};