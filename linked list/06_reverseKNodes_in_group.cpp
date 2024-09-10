Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return res;
}

Node* getKthNode(Node* head, int k){
    k -= 1;
    Node* temp = head;

    while(temp != nullptr && k--)
        temp = temp->next;

    return temp;
}

Node* kReverse(Node* head, int k) {
    if (head == nullptr || k == 1) return head;  // No need to reverse for k=1 or empty list.

    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){
        Node* kthNode = getKthNode(temp, k);

        if(kthNode == nullptr){
            if(prev) prev->next = temp; // Connect the remaining nodes if less than k.
            break;
        }

        Node* newNode = kthNode->next;  // Save the node after the kth node.
        kthNode->next = nullptr;        // Disconnect the kth node from the rest of the list.

        Node* reversedHead = reverse(temp);  // Reverse the sublist starting at temp.

        if(prev == nullptr)
            head = reversedHead;  // If this is the first block, update the head.
        else    
            prev->next = reversedHead;  // Otherwise, connect the previous block to the reversed block.

        prev = temp;           // temp is now the last node in the reversed block.
        temp = newNode;        // Move temp to the start of the next block to reverse.
    }
    
    return head;
}
