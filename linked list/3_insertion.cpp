// insertion at head

Node* insertAtHead(Node* head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

// insertion at tail

Node* insertAtTail(Node* head, int val){
    if(head == nullptr)
        return new Node(val);
    
    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// insertion at kth position
Node* insertAtKthPosition(Node* head, int k, int val){
    if(head == nullptr){
        if(k == 1)
            return new Node(val);
        else    
            return head;
    }

    if(k == 1)
        return new Node(val);

    int counter = 0;
    Node* temp = head;
    while(temp != nullptr){
        counter++;
        if(counter == k-1){
            Node* x = new Node(val);
            x->next = temp->next->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
return head;
}
