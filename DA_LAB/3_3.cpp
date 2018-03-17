#include<bits/stdc++.h>
using namespace std;

int arr[10100];

struct node
{
    int data;
    node* left;
    node* right;
};


void inorder(node *root)
{

    if(root)
    {
       inorder(root->left);
       printf("%d ",root->data);
       inorder(root->right);
    }
}

node* convert_to_BST(int arr[],int low,int high)
{
    if(low>high)
        return NULL;

    node* newnode=new node();

    int mid=low + (high-low)/2;

    newnode->data=arr[mid];
    newnode->left=convert_to_BST(arr,low,mid-1);
    newnode->right=convert_to_BST(arr,mid+1,high);

    return newnode;
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

    sort(arr,arr+n);

    node *root=convert_to_BST(arr,0,n-1);

    inorder(root);

    return 0;
}








