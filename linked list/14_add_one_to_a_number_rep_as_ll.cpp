// iterative approch

Node* reverse(Node* head){
        if (head == NULL || head->next == NULL)
            return head;

        Node* rest = reverse(head->next);
        head->next->next = head;

        head->next = NULL;

    return rest;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    head = reverse(head);
    
    int carry = 1;
    Node* temp = head;
    
    while(temp!=nullptr){
        temp->data = temp->data + carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
    temp = temp->next;
    }

    if(carry == 1){
        Node* newNode = new Node(carry);
        newNode->next = head;
    return newNode;
    }

    head = reverse(head);
return head;
}

// recursion 

int helper(Node* temp){
    if(temp == nullptr)
        return 1;
    
    int carry = helper(temp->next);
    temp->data += carry;

    if(temp->data < 10)
        return 0;
    temp->data = 0;
return 1;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(carry);
        newNode->next = head;
    return newNode;
    }
return head;
}