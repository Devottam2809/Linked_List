Node* deleteHead(Node* head){
    if(head == nullptr or head->next == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
return head;
}


Node* deleteTail(Node* head){
    if(head == nullptr or head->next == nullptr)
        return nullptr;
    Node* temp = head;
    while(temp->next != nunllptr){
        temp = temp->next;
    }
    Node* 
}