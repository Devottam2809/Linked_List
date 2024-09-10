// brute force (data replacement)
Node* sortList(Node *head){
    // Write your code here.
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == 0)  count0 +=1;
        if(temp->data == 1)  count1 +=1;
        if(temp->data == 2)  count2 +=1;

    temp = temp->next;
    }

    Node* current = head;
    
    while(count0--){
        current->data = 0;
        current = current->next;
    }
    
    while(count1--){
        current->data = 1;
        current = current->next;
    }

    while(count2--){
        current->data = 2;
        current = current->next;
    }
return head;
}


// optimized

Node* sortList(Node *head) {
    // Check if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* zerohead = new Node(-1);
    Node* zero = zerohead;
    Node* onehead = new Node(-1);
    Node* one = onehead;
    Node* twohead = new Node(-1);
    Node* two = twohead;


    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else if (temp->data == 2) {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (onehead->next != nullptr) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = nullptr;

    head = zerohead->next;

    // Clean up the dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}
