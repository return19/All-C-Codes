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

int extract_min(node *root)
{
    if(!root)
        return INT_MIN;

    while(root->left&&root->right)
    {
        if(root->left)
            root=root->left;
        else
            root=root->right;
    }

    return root->data;
}


int extract_max(node *root)
{
    if(!root)
        return INT_MAX;

    while(root->left&&root->right)
    {
        if(root->right)
            root=root->right;
        else
            root=root->left;
    }

    return root->data;
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

    printf("\nMAX VALUE : %d\n",extract_max(root));

    printf("\nMIN VALUE : %d\n",extract_min(root));


    return 0;
}







