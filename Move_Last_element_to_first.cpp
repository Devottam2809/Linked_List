#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createnode(node *root)
{
    int data;
    cout<<"Enter the data : ";
    cin>>data;

    node *p=(node *)malloc(sizeof(node));
    p->data=data;
    p->next=NULL;
    node *ptr;

    if(root==NULL)
    {
        root=p;
        ptr=root;
    return root;
    }
    ptr->next=p;
    ptr=p;
return root;
}

void print_list(node *root)
{
    node *current=root;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
}

void delete_head(node *root)
{
    node *current=root;
    node *temp=root->next;
    free(current);
    root=temp;
    print_list(root);
}

void delete_middle(node *root)
{
    cout<<"Enter the data to be deleted : ";
    int key;
    cin>>key;
    
    node *temp=root;
    node *prev;
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
        if(temp==NULL)
            cout<<"node not found";
    }
    prev->next=temp->next;
    free(temp);
    print_list(root);
}

int delete_end(node *root)
{
    node *current=root;
    node *temp=NULL;
    while(current->next!=NULL)
    {
        temp=current;
        current=current->next;
    }
    int val=current->data;
    temp->next=NULL;
    free(temp);
return val;
}

node *lastTOfirst(node *root)
{
    int val=delete_end(root);
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=root;
    //root->next=newnode;
    root=newnode;
return root;
}

int main()
{
    node *root=NULL;
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    for(int i=0;i<n;i++)
        root=createnode(root);
    node *temp=lastTOfirst(root);
    print_list(temp);
    
    return 0;
}
