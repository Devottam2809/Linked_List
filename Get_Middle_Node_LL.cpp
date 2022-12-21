// Get middle node of Linked List @devottam2809

#include <iostream>
#include <stdlib.h>>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createnode(node *head)
{
    cout<<"Enter the data = ";
    int data;
    cin>>data;

    node *p=(node *)malloc(sizeof(node));
    node *ptr;
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
                                         // Function to get the middle node 

int getmiddlenode(node *head)
{
	node *current=head;                   // making a copy of the head node
	node *newcurrent=head;  
	int counter = 0;                      // counter to count the number of nodes of the linked list
	int value;
	while(current!=NULL)                  // while loop to count the number of nodes
	{
		current=current->next;
		counter++;	
	}	
	int t=(counter/2)-1;                 // (counter/2)-1 to get the exact node
	while(t--)                           // traverse till the middle node is found
	{
		newcurrent=newcurrent->next;
	}
	value=newcurrent->data; 
return value;                          // return value of the new node
}

int main()
{
    cout<<"Enter the number of nodes = ";
    int n;
    cin>>n;

    node *head=NULL;
    for(int i=1;i<=n;i++)
    head=createnode(head);

    //printlist(head);
    int middle = getmiddlenode(head);
    cout<<"The data in middle node is = "<<middle;
return 0;
}
