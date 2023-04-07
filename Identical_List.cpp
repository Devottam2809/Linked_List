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

bool check(node *root1,node *root2)
{
    node *temp1=root1;
    node *temp2=root2;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
return (temp1 == NULL && temp2 == NULL);
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

int main()
{
    node *root1=NULL;
    node *root2=NULL;
    int n1;
    cout<<"Enter the number of nodes for list 1 : ";
    cin>>n1;

    for(int i=0;i<n1;i++)
        root1=createnode(root1);

    int n2;
    cout<<"Enter the number of nodes for list 2 : ";
    cin>>n2;
    for(int i=0;i<n2;i++)
        root2=createnode(root2);
    
    if(check(root1,root2))
        cout<<"OK";
    else    
        cout<<"NOT OK";
    
    return 0;
}
