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

void sum(node *root,int n)
{
    int sum=0;
    node *current=root;
    while(n--){
        sum+=current->data;
        current=current->next;
    }
cout<<sum;
}

void reverseList(node *root)
{
    node *current=root;
    node *prev=NULL;
    node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
sum(prev,4);
}

int main()
{
    node *root=NULL;
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    for(int i=0;i<n;i++)
        root=createnode(root);
    reverseList(root);
    return 0;
}
