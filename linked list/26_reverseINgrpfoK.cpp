// Optimized Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
class Solution {
private:
    // Helper function to reverse a linked list
    ListNode* reverseLinkedList(ListNode *head) 
    {
        ListNode *currNode = head, *prevNode = nullptr, *nextNode;
        while (currNode != nullptr) 
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    // Helper function to get the kth node from the current position
    ListNode* getKthNode(ListNode *temp, int k) 
    {
        k -= 1;
        while (temp != nullptr && k > 0) 
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    // Function to reverse nodes in k-group in a linked list
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head, *prevNode = nullptr, *nextNode = nullptr;
        // Iterate through the linked list
        while (temp != nullptr) 
        { 
            // Get the kth node from the current position
            ListNode *kthNode = getKthNode(temp, k);

            // If kth node is not found, connect the remaining nodes to the previous group
            if (kthNode == nullptr) 
            {
                if (prevNode != nullptr) 
                {
                    prevNode->next = temp;
                }
                break;
            }

            // Save the next node after kth node
            nextNode = kthNode->next;

            // Disconnect the kth node from the rest of the list
            kthNode->next = nullptr;

            // Reverse the current k-group and update head if necessary
            reverseLinkedList(temp);
            if (temp == head) 
            {
                head = kthNode;
            } else 
            {
                prevNode->next = kthNode;
            }

            // Update pointers for the next iteration
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};