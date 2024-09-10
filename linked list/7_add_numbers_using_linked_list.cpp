
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* dummynode = new Node(-1);
    Node* current = dummynode;
    int carry = 0;

    Node* temp1 = num1;
    Node* temp2 = num2;

    while(temp1 != nullptr || temp2 != nullptr || carry != 0) {
        int sum = carry;

        if(temp1) {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if(temp2) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        current->next = newNode;
        current = current->next;
    }

    return dummynode->next;
}
