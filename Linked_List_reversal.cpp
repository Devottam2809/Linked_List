// Linked List reversal @devottam2809

#include<iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createnode(node *head)
{
    node *p=(node *)malloc(sizeof(node));
    node *ptr;

    cout<<"Enter the data = ";
    int data;
    cin>>data;

    p->data=data;
    p->next=NULL;

    if(head==NULL)
    {
        head=p;
        ptr=head;
        return head;
    }
    else{
        ptr->next=p;
        ptr=p;
        return head;
    }
}

void reverse(node **head)
{
    node *prev=NULL;
    node *next=NULL;
    node *current=*head;
    while(current!=NULL)
    {
        next=current->next;                 // store current pointer
        current->next=prev;
        
        prev=current;                       // move next pointer to the head
        current=next;
    }
    *head=prev;
}

void printlist(node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main()
{
  cout<<"Enter the number of nodes of the List = ";
    int n;
    cin>>n;

    node *head=NULL;
    for(int i=0;i<n;i++)
        head=createnode(head);

    reverse(&head);

    printlist(head);
    return 0;
}
