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

int getlength(node *root)
{
    node *temp=root;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
return len;
}

void middleTofirst(node *root)
{
    int len=getlength(root)/2;
    node *current=root;
    node *prev=NULL;
    while(len--)
    {
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    current->next=root;
    root=current;
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
    //print_list(root);
    middleTofirst(root);
    
    return 0;
}
