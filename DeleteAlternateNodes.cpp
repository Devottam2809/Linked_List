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

void print_list(node *root)
{
    node *current = root;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

void delALT(node *root)
{
    node *ptr=root;
    node *temp=NULL;
    while(ptr!=NULL && ptr->next!=NULL)
    {
        temp=ptr->next;
        ptr->next=temp->next;
        free(temp);
        ptr=ptr->next;
    }
print_list(root);
}


int main()
{
    node *root = NULL;
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    for (int i = 0; i < n; i++)
        root = createnode(root);

    delALT(root);
    return 0;
}
