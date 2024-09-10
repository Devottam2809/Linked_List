// brute force
int length(Node* head){
    
    Node* temp = head;
    int counter =0;
    
    while(temp != nullptr){
        counter++;
        temp = temp->next;
    }

return counter;
}

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    
    int len = length(head);
    
    if(len == K){
        Node* temp = head;
        head = head->next;
        delete temp;
    return head;
    }

    Node* temp = head;
    len = len - K;
    
    while(temp != nullptr){
        len--;
        if(len == 0)
            break;
        temp = temp->next;
    }
    
    Node* delNode = temp->next;
    delete delNode;
    temp->next = temp->next->next;
return head;
}

// optimized


Node* removeKthNode(Node* head, int K)
{

    
    // Write your code here.
    Node* fast = head;
    Node* slow = head;

    for(int i=0;i<K;i++)
        fast = fast->next;
    
    if(fast == nullptr)     return head->next;

    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
return head;
}