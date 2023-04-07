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

int getlength(node *root)
{
    int length=0;
    node *temp=root;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
return length;
}

int Nthndoe(node *root, int n)
{
    node *temp=root;
    int len=getlength(root);
    int dist=len-n;
    while(dist--)
    {
        temp=temp->next;
    }
return temp->data;
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
    int n1;
    cout<<"Enter the number of nodes for list 1 : ";
    cin>>n1;

    for(int i=0;i<n1;i++)
        root1=createnode(root1);

    //print_list(root1);
    cout<<Nthndoe(root1,4);
    return 0;
}
