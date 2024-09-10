class Browser {
public:
    Node* currentPage;

    Browser(string &homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string &url) {
        Node* newNode = new Node(url);
        newNode->back = currentPage;  // Set the back pointer of the new node to the current page
        currentPage->next = newNode;  // Set the next pointer of the current page to the new node
        currentPage = newNode;        // Move the current page to the new node
    }

    string back(int steps) {
        while (steps > 0 && currentPage->back != nullptr) {
            currentPage = currentPage->back;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};





