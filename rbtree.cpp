#include<bits/stdc++.h>
using namespace std;

struct node{
    node* l;
    node* r;
    node* p;
    int val;
    int c;
    int h;
};

int getH(node* root){
    int l=0,r=0;
    if(root->l)
        l = root->l->h;
    if(root->r)
        r = root->r->h;
    return max(l,r)+1;
}

node* rotateleft(node* root){
    node* x = root->r;
    node* y = x->l;

    node* p = root->p;
    root->p = x;

    x->l = root;
    root->r = y;

    x->p = p;
    y->p = root;

    if(x->p!=NULL)
        if(x->p->l == root)
            x->p->l = x;
        else
            x->p->r = x;

    x->h = getH(x);
    root->h = getH(root);
    return x;
}

node* rotateright(node* root){
    node* x = root->l;
    node* y = x->r;

    node* p = root->p;
    root->p = x;

    x->r = root;
    root->l = y;

    x->p = p;
    y->p = root;

    if(x->p!=NULL)
        if(x->p->l == root)
            x->p->l = x;
        else
            x->p->r = x;

    x->h = getH(x);
    root->h = getH(root);
    return x;
}

void insertBST(node* &root,node* newnode){

    if(!root){
        root=newnode;
        return;
    }
    node* temp = root;
    while(1){
      //  cout<<temp->val<<" "<<newnode->val<<endl;
        if(temp->val < newnode->val){
            if(temp->r == NULL){
                temp->r = newnode;
                newnode->p = temp;
                return;
            }
            temp = temp->r;
        }else {
            if(temp->l == NULL){
                temp->l = newnode;
                newnode->p = temp;
                return;
            }
            temp=temp->l;
        }
    }
}

void fixViolation(node* &root){
    node* temp = root;
    while(temp->p!=NULL && temp->c == 2 && temp->p->c == 2){
         //   cout<<"h"<<endl;
        node* p = temp->p;
        node* gp = p->p;
        if(p == gp->l){
            node* uc = gp->r;

            if(uc->c==2){
                p->c = 1;
                uc->c = 1;
                gp->c = 2;
                temp = gp;
            } else{
                if(p->r==temp){
                    gp->l = rotateleft(p);
                    temp=p;
                    p = temp->p;
                }

                p->c = 1;
                gp->c = 2;
                rotateright(gp);
            }
        }else{
            node* uc = gp->l;

            if(uc->c==2){
                p->c = 1;
                uc->c = 1;
                gp->c = 2;
                temp = gp;
            } else{
                if(p->l==temp){
                    gp->r = rotateright(p);
                    temp = p;
                    p = temp->p;
                }

                p->c = 1;
                gp->c = 2;
                rotateleft(gp);
            }
        }
    }
    root->c = 1;
}

void insertRBTree(node* &root,int key){
    node *newnode = new node;
    newnode->val = key;
    newnode->l = NULL;
    newnode->r = NULL;
    newnode->p = NULL;
    newnode->c = 2;

    insertBST(root,newnode);
    fixViolation(newnode);
}

void inorder(node* root){
    if(root){
        inorder(root->l);
        cout<<root->val<<" ";
        inorder(root->r);
    }
}

int main()
{
    int i,j,k;

    node* root = NULL;

    insertRBTree(root,10);
        insertRBTree(root,20);
            insertRBTree(root,5);
                insertRBTree(root,15);
                insertRBTree(root,15);
                insertRBTree(root,55);
                insertRBTree(root,65);
                insertRBTree(root,35);

    inorder(root);

    return 0;
}














