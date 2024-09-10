// using stack

// 
void reverse(){
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
}

Node* reverse(Node* head){
        if (head == NULL || head->next == NULL)
            return head;

        Node* rest = reverse(head->next);
        head->next->next = head;

        head->next = NULL;

        return rest;
}