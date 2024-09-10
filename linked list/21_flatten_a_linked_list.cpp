// M1

Node* convertArrToLinkedList(vector<int>& arr){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    for(int i = 0; i < arr.size(); i++){
        temp->child = new Node(arr[i]); 
        temp = temp->child; 
    }
    return dummyNode->child; 
}

Node* flattenLinkedList(Node* head) {
    vector<int> arr;
    while (head != nullptr) {
        Node* t2 = head;
        while (t2 != nullptr) {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        head = head->next;
    }
    sort(arr.begin(), arr.end());
    return convertArrToLinkedList(arr);
}

// M2

Node* merge(Node* list1, Node* list2){

    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

Node* flattenLinkedList(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);

    return head;
}
