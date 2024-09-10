// M1

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_map<Node*, int> umap;

    Node* temp1 = firstHead;
    while(temp1 != nullptr){
        umap[temp1]++;
        temp1 = temp1->next;
    }

    Node* temp2 = secondHead;
    while(temp2 != nullptr){

        if(umap.find(temp2) != umap.end()){
            return temp2; 
        }
        temp2 = temp2->next;
    }
    return nullptr;
}

// M2

Node* collisionDetected(Node* temp1, Node* temp2, int dis) {
    while (dis--) {
        if (temp2 == nullptr) return nullptr; // Added null check
        temp2 = temp2->next;
    }

    while (temp1 != temp2) {
        if (temp1 == nullptr || temp2 == nullptr) return nullptr; // Added null check
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* findIntersection(Node *firstHead, Node *secondHead) {
    // Write your code here

    int len1 = 0, len2 = 0;

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while (temp1 != nullptr) {
        len1 += 1;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        len2 += 1;
        temp2 = temp2->next;
    }

    if (len1 < len2) {
        return collisionDetected(firstHead, secondHead, len2 - len1);
    } else {
        return collisionDetected(secondHead, firstHead, len1 - len2);
    }
}

// M3


Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == nullptr or secondHead == nullptr)
        return nullptr;
    
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while(temp1 != temp2){
        
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2)  return temp1;

        if(temp1 == nullptr)    temp1 =secondHead;
        if(temp2 == nullptr)    temp2 =firstHead;

    }
return temp1;
}
