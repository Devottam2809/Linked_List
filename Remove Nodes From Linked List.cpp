// Leetcode2487 Remove Nodes From Linked List     @devottam2809


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
private:
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
    ListNode* removeNodes(ListNode* head) {   
    head=rev(head);
    stack<int>st;
    ListNode *temp=head;
    while(current!=NULL){
        if(st.size()==0)
            st.push(temp->val);
        if(st.top()>temp->val)
            st.push(temp->val);
        temp=temp->next;
    }
    ListNode *dummy=new ListNode(-1);
    ListNode *current=dummy;
    while(st.size()>0){
        current->next=new ListNode(st.top());
        current=current->next;
        st.pop();
    }
    return dummy->next;
    }
};
