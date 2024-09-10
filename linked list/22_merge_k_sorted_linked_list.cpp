// brute force

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

// optimized

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ListNode* node = it.second;
            if (node->next) {
                pq.push({node->next->val, node->next});
            }

            temp->next = node;                                                                                                                                                                                                                                                                                                                                                                                          
            temp = temp->next;
        }

        return dummyNode->next;
    }
};