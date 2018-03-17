#include<bits/stdc++.h>
using namespace std;

int arr[10100];

struct node
{
    int data;
    node* left;
    node* right;
};

node *root=NULL;

void insert_node(int data)
{
    node *newnode=new node();

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    node *root1=root;

    if(root==NULL)
    {

        root=newnode;
        return;
    }

    while(root1)
    {

       // cout<<"insert "<<data<<endl;
        if(data>=root1->data)
        {
            if(root1->right==NULL)
            {
                root1->right=newnode;
                return;
            }else
                root1=root1->right;
        }
        else
        {
            if(root1->left==NULL)
            {
                root1->left=newnode;
                return;
            }else
                root1=root1->left;
        }
    }

}

int search_BST(node *root,int data)
{
    while(root)
    {
        if(root->data==data)
            return 1;
        else if(data>root->data)
            root=root->right;
        else
            root=root->left;
    }

    return 0;
}

void inorder(node *root)
{

    if(root)
    {
       inorder(root->left);
       printf("%d ",root->data);
       inorder(root->right);
    }
}


int main()
{
    int i,j,k;

    int temp;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    j=0;
    for(i=0;i<n;i++)
    {
        if(search_BST(root,arr[i]))
            continue;
        else
        {
            arr[j++]=arr[i];
            insert_node(arr[i]);
        }
    }

    n=j;

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";




    return 0;
}







