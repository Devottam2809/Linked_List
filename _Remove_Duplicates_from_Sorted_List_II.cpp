// Leetcode 82  Remove Duplicates from Sorted List II   @devottam2809

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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mp;
        ListNode *temp=head;
        ListNode *temp1 = head;
        while(temp1!=NULL){
            mp[temp1->val]++;
            temp1=temp1->next;
        }

        ListNode *dummy=new ListNode(-1);
        ListNode *current=dummy;

        while(temp!=NULL){
            if(mp[temp->val] == 1){
                current->next=new ListNode(temp->val);
                current=current->next;
            }
        temp=temp->next;
        } 
return dummy->next;
    }
};
