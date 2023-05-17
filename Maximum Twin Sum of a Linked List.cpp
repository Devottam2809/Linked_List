// Leetcode 2130  Maximum Twin Sum of a Linked List


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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode *temp=head;
        ListNode *current=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
    
    int mx=INT_MIN;
    while(st.size()>0 && current!=nullptr){
        int sum=st.top()+current->val;
        mx=max(mx,sum);
        st.pop();
        current=current->next;
    }
return mx;
    }
};
