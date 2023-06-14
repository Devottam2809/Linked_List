// Leetcode 2181     Merge Nodes in Between Zeros     @devottam2809

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
    ListNode* mergeNodes(ListNode* head) {
        stack<int>st;
        ListNode *temp=head;

        ListNode *dummy=new ListNode(-1);
        ListNode *current=dummy;
        while(temp!=nullptr){
            if(st.size()==0 && temp->val==0)
                st.push(temp->val);
            
            else if(st.size()>0 && temp->val!=0)
                st.push(temp->val);
            else if(st.size()>0 && temp->val==0){
                int sum=0;
                while(st.top()!=0){
                    sum+=st.top();
                    st.pop();
                }
                current->next=new ListNode(sum);
                current=current->next;
            }
            temp=temp->next;
        }
    return dummy->next;
    }
};
