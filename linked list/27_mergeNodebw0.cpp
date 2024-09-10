// brute force stack 
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


// optimized

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(10);
        ListNode* q=dummy;
        ListNode* p=head->next;
        int sum=0;
        while(p!=NULL){
            if(p->val!=0){
                sum+=p->val;
            }else{
                ListNode* add=new ListNode(sum);
                q->next=add;
                q=q->next;
                sum=0;
            }
            p=p->next;
        }
        return dummy->next;

    }
};