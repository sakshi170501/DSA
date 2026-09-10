class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1,l2);

    }
    //     ListNode* res = NULL;
    //     ListNode* curr = NULL;
    //     int carry = 0;

    //     while (l1 != NULL || l2 != NULL || carry != 0) {

    //         int sum = carry;

    //         if (l1 != NULL) {
    //             sum += l1->val;
    //             l1 = l1->next;
    //         }

    //         if (l2 != NULL) {
    //             sum += l2->val;
    //             l2 = l2->next;
    //         }

    //         ListNode* newNode = new ListNode(sum % 10);
    //         carry = sum / 10;

    //         if (res == NULL) {
    //             res = newNode;
    //             curr = newNode;
    //         }
    //         else {
    //             curr->next = newNode;
    //             curr = curr->next;
    //         }
    //     }

    //     return res;
    // }
    ListNode* recursive(ListNode* l1,ListNode* l2,int carry=0){
        if(!l1 && !l2 && !carry){
            return nullptr;
        }
        int a=l1?l1->val:0;
        int b=l2?l2->val:0;
        int sum=a+b+carry;
        int digit=sum%10;
        carry=sum/10;
        ListNode* ans=new ListNode(digit);
        ans->next=recursive(l1?l1->next:l1,l2?l2->next:l2,carry);
        return ans;
    }
};