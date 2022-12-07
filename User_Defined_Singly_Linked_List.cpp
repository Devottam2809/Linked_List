// User Defined Linked List @Devottam2809

#include <iostream>
#include <stdlib.h>

using namespace std;

// Create the structure for Singly Linked List

struct node{
    int data;
    node *next;
};


node *createnode(node *head_ref)
{
// Take user input of the data for the new node
   
   int data;
    cout<<"Enter the data = ";
    cin>>data;
    
//Creation of the new node

    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    
    node *ptr;
    
//Check if head is NULL or not
    
    if(head_ref==NULL)
    {
        head_ref=new_node;    // move head pointer to new node
        ptr=head_ref;         // take copy of the head node (for traversal , shown below)
        return head_ref;      // return the head pointer
    }
    else{
        ptr->next=new_node;   // now point head to the new node
        ptr=new_node;         // take copy of the new node in ptr
        return head_ref;      // return the head pointer
    }
}

//Print the Linked List

void printlist(node *head_ref)
{
    while(head_ref!=NULL)
    {
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;

    }
}

int main()
{
    cout<<"Enter the number of nodes = ";
    int n;
    cin>>n;
    
//Creation of the head node
    
    node *head_ref=NULL;
    cout<<"\n";

    for(int i=0;i<n;i++)

        head_ref=createnode(head_ref);
    
    printlist(head_ref);

    return 0;
}
