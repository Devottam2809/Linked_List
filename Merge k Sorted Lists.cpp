// Leetcode 23  Merge k Sorted Lists    @devottam2809

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>nums;
        ListNode *temp;
        for(int i=0;i<lists.size();i++){
            temp=lists[i];
            while(temp!=NULL){
                nums.push_back(temp->val);
                temp=temp->next;
            }
        }

    sort(nums.begin(),nums.end());
    ListNode *dummy=new ListNode(-1);
    ListNode *current=dummy;
    for(auto i:nums){
        current->next=new ListNode(i);
        current=current->next;
    }
    return dummy->next;
    }
};
