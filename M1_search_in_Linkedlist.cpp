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

bool search(node *root, int x)
{
    node *current=root;
    vector<int>v;
    while(current!=NULL)
    {
        v.push_back(current->data);
        current=current->next;
    }
    vector<int>:: iterator it;
    it=find(v.begin(),v.end(),x);
    if(it!=v.end())
        return true;
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
    search(root,5);
    return 0;
}
