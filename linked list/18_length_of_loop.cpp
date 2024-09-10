// brute force

int lengthOfCycle(Node *head)
{
	//	Write your code here
    unordered_map<Node*,int>umap;
    Node* temp = head;
    int timer = 1;

    while(temp !=nullptr){
        if(umap.find(temp) != umap.end()){
            int value = umap[temp];
            return timer - value; 
        }
        umap[temp] = timer;
        timer += 1;
        temp = temp->next;
    }
return 0;
}

// optimized method 
int findLen(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;

    while(slow != fast){
        count += 1;
        fast = fast->next;
    }

return count;
}

bool detectCycle(Node *head)
{
	//	Write your code here
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr and fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)    return findLen(slow,fast);
    }
return 0;
}

