// brute force approch

Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2 + 1;
    temp = head;

    while (temp != null) {
        mid = mid - 1;

        if (mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}


// optimized approch

Node *findMiddle(Node *head) {
    Node *slow = head; 
    Node *fast = head; 

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 
    }
    return slow; 
}