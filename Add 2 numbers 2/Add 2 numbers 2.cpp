// Add 2 numbers 2 Leetcode 445   @devottam2809

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
    ListNode *rev(ListNode *head){
        ListNode *current=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;

            prev=current;
            current=next;
        }
    return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);

        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
        sum+=carry;
        carry=sum/10;
        ListNode *node=new ListNode(sum%10);
        temp->next=node;
        temp=temp->next;
        }
    dummy=rev(dummy->next);
    return dummy;
    }
};
