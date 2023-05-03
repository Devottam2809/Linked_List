// LeetCode 203  Remove Linked List Elements    @devottam2809

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *current=head;
        while(current){
            if(current->next && current->next->val==val){
                current->next=current->next->next;
            }
            else{
                current=current->next;
            }
        }
    if(head && head->val==val){
        head=head->next;
    }
return head;
    }
};
