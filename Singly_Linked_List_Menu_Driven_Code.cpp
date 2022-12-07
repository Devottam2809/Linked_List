// Singly Linked List Menu Driven Code @Devottam2809

#include <iostream>
#include <stdlib.h>

using namespace std;

// Create the structure for Singly Linked List

struct node{
    int data;
    node *next;
};

node *createnode(node *head)
{
// Take user input of the data for the new node
  
    int data;                               
    cout<<"Enter the data = ";
    cin>>data;

  //Creation of the new node
  
    node *p=(node*)malloc(sizeof(node));   
    p->data=data;                           
    p->next=NULL;                           
  
    node *ptr;                              
    if(head==NULL)
    {
        head=p;         // move head pointer to new node
        ptr=head;       // take copy of the head node (for traversal , shown below)
        return head;    // return the head pointer
    }
    else{
        ptr->next=p;    // now point head to the new node
        ptr=p;          // take copy of the new node in ptr
        return head;    // return the head pointer
    }
}

void deletenode(node **head,int key)
{
    node *temp=(*head);                         // creation of temporary node
    node *prev;                                 // created to take copy of previous node

    if(temp!=NULL && temp->data==key)           // for deletion of head node
    {
        (*head)=temp->next;
        free(temp);
        return ;
    }
    else{
        while(temp!=NULL && temp->data!=key)    // for deletion of other middle and last node of linked list
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        	return ;
        prev->next=temp->next;
        free(temp);
    }
}

void insertathead(node **head_ref)
{
	int data;
	cout<<"Enter the data to be inserted = ";
	cin>>data;
	
	node *new_node=(node *)malloc(sizeof(node));        // creation of new node for the head
	new_node->data=data;                                //assign the data value to the new node
	new_node->next=(*head_ref);                         // assign new node next to head
	(*head_ref)=new_node;                               // make new node as head
}

void insertadmiddle(node *head_ref,int key)
{
	node *current=head_ref;
	int data;
	cout<<"Enter the data to be inserted = ";
	cin>>data;
	
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=data;
	while(current->data!=key)                           //traverse till the key element is found
	{
		current=current->next;	
	}
	new_node->next=current->next;
	current->next=new_node;
}

void insertatend(node** head_ref)
{
	int data;
	cout<<"Enter the data to be inserted = ";
	cin>>data;
   	
    node* new_node = (node *)malloc(sizeof(node));
    node *last = *head_ref;
    new_node->data =data;

    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL)                          // traverse till the pointer reaches the last node
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

//Print the Linked List

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
  
//User Menu for all operations 
	  cout<<"Insertion\n";
    cout<<"\t1 . For insertion at head\n";
    cout<<"\t2 . For insertion at middle\n";
    cout<<"\t3 . For insertion at end\n";
    cout<<"\n";
    cout<<"Deletion\n";
    cout<<"\t4 . For deletion at head\n";
    cout<<"\t5 . For deletion at middle\n";
    cout<<"\t6 . For deletion at end\n";
    cout<<"\n";
	
	int n;
    cout<<"Enter the number of nodes = ";
    cin>>n;

//Creation of the head node
  
    node *head=NULL;
    
	for(int i=0;i<n;i++)
        head=createnode(head);

    cout<<"\n";
    
    cout<<"The required LL is\n";
    printlist(head);
    
   cout<<"\n";
    int choice;
    cout<<"Enter the choice = ";
    cin>>choice;
    
    if(choice==1)
    	{
    		insertathead(&head);
    		printlist(head);
		}
    else if(choice==2)
    	{
    		cout<<"Enter the element after which you want to insert = ";
    		int pos;
    		cin>>pos;
    		insertadmiddle(head,pos);
    		printlist(head);
		}
    else if(choice==3)
    	{
    		insertatend(&head);
    		printlist(head);
		}
    else if(choice==4)
    	{
    		int key;
    		cout<<"Enter the element to be deleted = ";
    		cin>>key;
			deletenode(&head,key);
    		printlist(head);
		}
	else if(choice==5)
    	{
    		int key;
    		cout<<"Enter the element to be deleted = ";
    		cin>>key;
			deletenode(&head,key);
    		printlist(head);
		}
	else if(choice==6)
    	{
    		int key;
    		cout<<"Enter the element to be deleted = ";
    		cin>>key;
			deletenode(&head,key);
    		printlist(head);
		}
    return 0;
}
