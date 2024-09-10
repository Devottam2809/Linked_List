Node *cloneLL(Node *head){
    Node* temp = head;
    // Create an unordered_map to map original
    // nodes to their corresponding copied nodes
    unordered_map<Node*, Node*> mpp;

    // Step 1: Create copies of each node
    // and store them in the map
    while(temp != NULL){
        // Create a new node with the
        // same data as the original node
        Node* newNode = new Node(temp->data);
        // Map the original node to its
        // correspo nding copied node in the map
        mpp[temp] = newNode;
        // Move to the next node in the original list
        temp = temp->next;
    }
    
    temp = head;
    // Step 2: Connect the next and random
    // pointers of the copied nodes using the map
    while(temp != NULL){
        // Access the copied node corresponding
        // to the current original node
        Node* copyNode = mpp[temp];
        // Set the next pointer of the copied node
        // to the copied node mapped to the
        // next node in the original list
        copyNode->next = mpp[temp->next];
        // Set the random pointer of the copied node
        // to the copied node mapped to the
        // random node in the original list
        copyNode->random = mpp[temp->random];
        // Move to the next node
        // in the original list
        temp = temp->next;
    }
    
    // Return the head of the
    // deep copied list from the map
    return mpp[head];
}


// M2

void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        // Create a new node with the same data
        Node* copy = new Node(temp->data);  
        
        // Point the copy's next to
        // the original node's next
        copy->next = nextElement;  
        
        // Point the original
        // node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = nextElement;         
    }
}

// Function to connect random
// pointers of the copied nodes
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        // Access the copied node
        Node* copyNode = temp->next;    
        
        // If the original node
        // has a random pointer
        if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copyNode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copyNode->random = NULL;   
        }
        
         // Move to the next original node
        temp = temp->next->next;   
    }
}

// Function to retrieve the
// deep copy of the linked list
Node* getDeepCopyList(Node* head){
    Node* temp = head;
     // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;   
}

// Function to clone the linked list
Node *cloneLL(Node *head){
    // If the original list
    // is empty, return null
    if(!head) return nullptr;   
    
     // Step 1: Insert copy of
     // nodes in between
    insertCopyInBetween(head); 
    // Step 2: Connect random
    // pointers of copied nodes
    connectRandomPointers(head);  
    // Step 3: Retrieve the deep
    // copy of the linked list
    return getDeepCopyList(head); 
}