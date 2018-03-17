
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

void extract_nth_min(node *root,int &n,int &ans)
{
    if(root)
    {
        extract_nth_min(root->left,n,ans);

        if(n==1)
            {
                ans=root->data;
                n=INT_MAX;
            }
            n--;
        extract_nth_min(root->right,n,ans);
    }
}


void extract_nth_max(node *root,int &n,int &ans)
{
    if(root)
    {
        extract_nth_max(root->right,n,ans);

        if(n==1)
            {
                ans=root->data;
                n=INT_MAX;
            }
            n--;
        extract_nth_max(root->left,n,ans);
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
        scanf("%d",&temp);

        insert_node(temp);
    }

    inorder(root);
    int ans1,ans2;
    int nth=4;
    extract_nth_max(root,nth,ans1);

    nth=4;
    extract_nth_min(root,nth,ans2);
    printf("\n4ht MAX VALUE : %d\n",ans1);

    printf("\n4th MIN VALUE : %d\n",ans2);


    return 0;
}







