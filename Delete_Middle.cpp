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

int main()
{
    node *root=NULL;
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    for(int i=0;i<n;i++)
        root=createnode(root);
    
    print_list(root);
    cout<<endl;
    delete_middle(root);
    return 0;
}
