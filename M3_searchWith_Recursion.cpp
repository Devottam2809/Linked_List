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

bool searchRECURSION(node *root, int x)
{
    node *current=root;
    if(current==NULL)
        return false;
    if(current->data==x)
        return true;
    return searchRECURSION(current->next,x);
return false;
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
    searchRECURSION(root,5);
    return 0;
}
