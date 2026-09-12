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

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* forward = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;   // you missed this
    }

    int getlen(ListNode*& head) {
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool isPalindrome(ListNode* head) {

        int len = getlen(head);

        ListNode* mid = middleNode(head);

        ListNode* finalnode = NULL;

        if (len & 1) {
            // Odd length
            finalnode = mid->next;
        }
        else {
            // Even length
            finalnode = mid;
        }

        finalnode = reverseList(finalnode);

        ListNode* temp = head;

        while (temp != NULL && finalnode != NULL) {

            if (temp->val != finalnode->val) {
                return false;
            }

            temp = temp->next;
            finalnode = finalnode->next;
        }

        return true;
    }
};