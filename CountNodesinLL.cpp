#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *createnode(node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    node *ptr;

    if (root == NULL)
    {
        root = p;
        ptr = root;
        return root;
    }
    ptr->next = p;
    ptr = p;
    return root;
}

int nodecount(node *slow)
{
    node *temp=slow;
    int counter=1;
    while(temp->next!=slow)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

int loopdetect(node *root)
{
    node *slow=root;
    node *fast=root;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return nodecount(slow);
    }
return 0;
}

int main()
{
    node *root = NULL;
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    for (int i = 0; i < n; i++)
        root = createnode(root);
    root->next->next=root;
    cout<<loopdetect(root);
    return 0;
}
