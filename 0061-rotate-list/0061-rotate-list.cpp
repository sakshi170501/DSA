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
    ListNode* rotateonce(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        if(head!=NULL && head->next==NULL){
            return head;
        }
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
            
        }
        temp->next=head;
        prev->next=NULL;
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL||head->next==NULL||k==0){
        return head;
       }
       int n=0;
       ListNode* temp=head;
       while(temp!=NULL){
        n++;
        temp=temp->next;
       }
       k=k%n;
       if(k==0){
        return head;
       }
       head=rotateonce(head);
       return rotateRight(head,k-1);
    }
};