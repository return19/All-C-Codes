#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};

node* root = NULL;

node* search(node* root, int val, node* &par){
    if(!root)
        return NULL;

    while(1){
        if(root->val > val)
        {
            if(root->left == NULL){
                return NULL;
            }
            par = root;
            root = root->left;
        } else if(root->val < val) {
            if(root->right == NULL){
                return NULL;
            }
            par = root;
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

void insert(node* &root, int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
        return;
    }

    node* temp = root;

    while(1){
        if(temp->val >= val)
        {
            if(temp->left == NULL){
                temp->left = newnode;
                return;
            }
            temp = temp->left;
        } else {
            if(temp->right == NULL){
                temp->right = newnode;
                return;
            }
            temp = temp->right;
        }
    }
}

int max_val(node *root){
    if(!root)
        return INT_MIN;
    while(root->right)
        root = root->right;
    return root->val;
}

int min_val(node *root){
    if(!root)
        return INT_MAX;
    while(root->left)
        root = root->left;
    return root->val;
}

node* deleteNodeUtil(node* root){

    if(root->left == NULL && root->right == NULL)
        return NULL;

    if(root->left == NULL)
        return root->right;
    if(root->right == NULL)
        return root->left;

    node* par = root;
    node* nextRoot = root->left;

    while(nextRoot -> right){
        par = nextRoot;
        nextRoot = nextRoot->right;
    }

    root->val = nextRoot->val;
    if(par->left == nextRoot)
        par->left = deleteNodeUtil(nextRoot);
    else
        par->right = deleteNodeUtil(nextRoot);
    return root;
}

void deleteNode(node* &root, int val){
    node* par = NULL;
    node* requiredNode = search(root,val,par);

    if( !requiredNode)
    {
        cout<<"Value not found"<<endl;
        return;
    }

    if(par){
        if(par->left == requiredNode)
            par->left = deleteNodeUtil(requiredNode);
        else
            par->right = deleteNodeUtil(requiredNode);
    } else {
        root = deleteNodeUtil(requiredNode);
    }
}

void inorder(node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    int i,j,k;

    while(1){
        cout<<"\n1. Search"<<endl;
        cout<<"2. Max value"<<endl;
        cout<<"3. Min value"<<endl;
        cout<<"4. Insert"<<endl;
        cout<<"5. Delete"<<endl;
        cout<<"6. Inorder"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice : ";
        int choice;
        cin>>choice;

        int temp;
        node* par;
        node* res;

        switch(choice){
            case 1:
                cout<<"\nEnter the value : "<<endl;
                cin>>temp;
                par = NULL;
                res = search(root,temp,par);
                if(!res)
                    cout<<"Not found"<<endl;
                else
                    cout<<"Value found"<<endl;
                break;
            case 2:
                temp = max_val(root);
                if(temp == INT_MIN)
                    cout<<"Tree empty"<<endl;
                else
                    cout<<"Max value : "<<temp<<endl;
                break;
            case 3:
                temp = min_val(root);
                if(temp == INT_MAX)
                    cout<<"Tree empty"<<endl;
                else
                    cout<<"Min value : "<<temp<<endl;
                break;
            case 4:
                cout<<"\nEnter the value : "<<endl;
                cin>>temp;
                insert(root,temp);
                break;
            case 5:
                cout<<"\nEnter the value : "<<endl;
                cin>>temp;
                deleteNode(root,temp);
                break;
            case 6:
                inorder(root);
                break;
            case 0:
                return 0;
            default:
                cout<<"Invalid input"<<endl;
        }
    }

    return 0;
}
