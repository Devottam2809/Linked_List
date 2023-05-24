// Leetode 328     Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        int i=1;
        vector<int>odd;
        vector<int>even;
        ListNode *temp=head;
        while(temp!=nullptr){
            if(i%2==0)
                even.push_back(temp->val);
            else
                odd.push_back(temp->val);
            i++;
        temp=temp->next;
        }
    ListNode *dummy=new ListNode(-1);
    ListNode *current=dummy;
    for(auto x: odd){
        current->next=new ListNode(x);
        current=current->next;
    }
    for(auto x: even){
        current->next=new ListNode(x);
        current=current->next;
    }
    
return dummy->next;
    }
};
