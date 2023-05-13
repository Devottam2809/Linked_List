// Leetcode 1019  Next Greater Node In Linked List      @devottam2809

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
        ListNode *prev=nullptr;
        ListNode *next=nullptr;
        while(current!=nullptr){
            next=current->next;
            current->next=prev;

            prev=current;
            current=next;
        }
    return prev;
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<int>s;
        head=rev(head);
    while(head!=nullptr){
        if(s.size()==0)
            ans.push_back(0);
        else if(s.top()>head->val)
            ans.push_back(s.top());
        else if(s.size()>0 && s.top()<=head->val)
        {
            while(s.size()>0 && s.top()<=head->val)
                s.pop();
                if(s.size()==0)
                    ans.push_back(0);
                else
                    ans.push_back(s.top());
        }
    s.push(head->val);
    head=head->next;
    }
reverse(ans.begin(),ans.end());
return ans;
    }
};
