// brute force 
// use stack by adding elements in stack then while popping out elements 
// match the elemnts with the nodes of the linked list



Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;  
    }

    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;  
    Node* second = newHead; 
    
    while (second != NULL) {
        if (first->data != second->data) {
            reverseLinkedList(newHead);  
            return false;
        }

        first = first->next; 
        second = second->next;  
    }

    reverseLinkedList(newHead);  
    return true;  
}
