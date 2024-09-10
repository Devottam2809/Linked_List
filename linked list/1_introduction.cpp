// Array to linked list

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node(arr[0]);
    Node* current = head;
    int i=1;
    while(i<arr.size()){
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = current->next;
        i++;
    }
return head;     
}

// Length of Linked List

int length(Node *head)
{
	//Write your code here
    int length = 0;
    Node* current = head;
    while(current!=nullptr){
        length++;
        current = current->next;
    }
return length;
}

// Search element in linked List

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>* temp = head;
    while(temp!=nullptr){
        if(temp->data == k)
            return 1;

        temp = temp->next;
    }
return  0;
}

