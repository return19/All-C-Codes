#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* l;
    Node* r;
    int val;
    int h;
};

int getH(Node* node){
    int l=0,r=0;

    if(node->l)
        l = node->l->h;
    if(node->r)
        r = node->r->h;
    return max(l,r)+1;
}

Node* rightR(Node* root){
    Node* x = root->l;
    Node* y = x->r;

    x->r = root;
    root->l = y;

    root->h = getH(root);
    x->h = getH(x);
    return x;
}

Node* leftR(Node* root){
    Node* x = root->r;
    Node* y = x->l;

    x->l = root;
    root->r = y;

    root->h = getH(root);
    x->h = getH(x);
    return x;
}

Node* insertBST(Node* root,int k){
    if(!root){
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->val = k;
        newnode->l = NULL;
        newnode->r = NULL;
        newnode->h = 1;
        return newnode;
    }

    if(root->val < k)
        root->r = insertBST(root->r,k);
    else
        root->l = insertBST(root->l,k);

    int l=0,r=0;
    if(root->l)
        l = root->l->h;
    if(root->r)
        r = root->r->h;
    int bal = l-r;

    if(bal>1 && root->l->val > k)
        root = rightR(root);
    if(bal>1 && root->l->val < k)
    {
        root->l = leftR(root->l);
        root = rightR(root);
    }
    if(bal<-1 && root->r->val < k)
        root = leftR(root);
    if(bal<-1 && root->r->val > k){
        root->r = rightR(root->r);
        root = leftR(root);
    }
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->l);
        cout<<root->val<<" ";
        inorder(root->r);
    }
}

int main()
{
    int i,j,k;
    Node* root = NULL;
    root = insertBST(root,10);
    root = insertBST(root,30);
    root = insertBST(root,20);
    root = insertBST(root,5);
    root = insertBST(root,15);
    root = insertBST(root,60);

    inorder(root);
    return 0;
}











