
#include<bits/stdc++.h>
using namespace std;

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

void inorder(node *root)
{

    if(root)
    {
       inorder(root->left);
       printf("%d ",root->data);
       inorder(root->right);
    }
}

void print_range(node *root,int k1,int k2)
{
    if(!root)
        return;

        if(root->data>=k1&&root->data<=k2)
        {
             cout<<root->data<<" ";
            print_range(root->left,k1,k2);
            print_range(root->right,k1,k2);
        }
        else if(root->data>k2)
            print_range(root->left,k1,k2);
        else
            print_range(root->right,k1,k2);

}

int main()
{
    int i,j,k;

    int temp;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);

        insert_node(temp);
    }

    inorder(root);
    cout<<endl;
   print_range(root,2,7);

    return 0;
}



