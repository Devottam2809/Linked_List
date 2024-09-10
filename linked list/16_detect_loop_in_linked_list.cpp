// brute force

bool detectCycle(Node *head)
{
	//	Write your code here
    unordered_map<Node*,int>umap;
    Node* temp = head;

    while(temp !=nullptr){
        if(umap.find(temp) != umap.end())
            return true;
        else
            umap[temp]++;

    temp = temp->next;
    }
return false;
}

// optimized method 

bool detectCycle(Node *head)
{
	//	Write your code here
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr and fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)    return true;
    }
return false;
}

