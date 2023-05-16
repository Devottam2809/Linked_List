// Leetcode 1721 Swapping Nodes in a Linked List      @devottam2809

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
        int counter = 0;
        ListNode *current=head;
        ListNode *temp=head;

        while(temp!=nullptr){
            counter++;
            temp=temp->next;
        }

        int nums[counter];
        int i=0;
        while(current!=nullptr){
            nums[i]=current->val;
            current=current->next;
            i++;
        }
    int x = nums[k-1];  
    nums[k-1] = nums[counter-k];  
    nums[counter-k] = x; 
    ListNode *dummy=new ListNode(-1);
    ListNode *p=dummy;
    for(int j=0;j<counter;j++){
        p->next=new ListNode(nums[j]);
        p=p->next;
    }
return dummy->next;
    }
};  
