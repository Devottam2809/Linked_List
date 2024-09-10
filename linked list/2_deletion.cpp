// deletion of node from head 

Node* removehead(Node* head){
    if(head == nullptr) // if linked list empty
        return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
return head;
}

// deletion of node from tail 

Node* removeTail(Node* head){
    if(head == nullptr or head->next == nullptr) // if head is null or 
        return nullptr;     // linked list has element

    Node* temp = head;
    while(temp->next->next != nullptr){ // stop loop before last sec element
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

return head;
}

// delete node from kth position

Node* deleteKthNode(Node* head){
    if(head == nullptr)
        return nullptr;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
    return head;
    }

    int counter = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        counter++;
        if(counter == k){
            prev->next = prev->next->next;
            delete temp;
            break;
    }
    prev = temp;
    temp = temp->next;
}
}
// delete node with particular value

Node* deleteValueNode(Node* head, int element){
    if(head == nullptr)
        return nullptr;

    if(head->val == element){
        Node* temp = head;
        head = head->next;
        delete temp;
    return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        counter++;
        if(temp->val == element){
            prev->next = prev->enxt->next;
            delete temp;
            break;
    }
    prev = temp;
    temp = temp->next;
}