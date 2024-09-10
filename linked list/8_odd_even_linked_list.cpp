// brute force (data replacement)

Node* oddEvenList(Node* head)
{
	// Write your code here.

    if(head == nullptr or head->next == nullptr)
        return head;

    vector<int>nums;
    Node* temp1 = head;

    while(temp1 != nullptr or temp1->next != nullptr){
        nums.push_back(temp1->data);
        temp1 = temp1->next->next;
    }

    if(temp1)   nums.push_back(temp1->data);        // for odd number of elements

    Node* temp2 = head->next;
    while(temp2 != nullptr or temp2->next != nullptr){
        nums.push_back(temp2->data);
        temp2 = temp2->next->next;
    }

    if(temp2)   nums.push_ba ck(temp2->data);        // for odd number of elements

    Node* current = head;

    int i=0;
    
    while(current != nullptr){
        current->data = nums[i];
        i +=1;
        current = current->next;
    }

return head;
}

// optimized approch (link changing)

Node* oddEvenList(Node* head)
{
	// Write your code here.

     if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}