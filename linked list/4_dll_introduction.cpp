class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1,Node* next1, Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int i=1;
    while(i<arr.size()){
        Node* temp = new Node(arr[i],nullptr,prev);
        i++;
        prev->next = temp;
        prev = temp;
    }
return head;
}

