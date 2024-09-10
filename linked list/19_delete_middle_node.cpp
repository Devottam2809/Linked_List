// find and delete the middle node using hare and tortoise algorithm
// or
// reach the node before the middle node and change the pointers


Node *deleteMiddle(Node *head) {
    Node* temp = head;
    int n = 0;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    
    int res = n/2;
    temp = head;
    while(temp!=NULL){
        res --;
        if(res==0){
            Node* middle = temp->next;
            temp->next = temp->next->next;
            free(middle);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// optimized

Node *deleteMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    fast = head->next->next; // skip one step of fast so that slow is one step before the node to be deleted

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}