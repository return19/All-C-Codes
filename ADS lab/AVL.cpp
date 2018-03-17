#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
    int h;
};

node* root;

int getH(node* root){
    if(!root)
        return 0;
    int lh=0,rh=0;
    if(root->left)
        lh = root->left->h;
    if(root->right)
        rh = root->right->h;
    return max(lh,rh)+1;
}

node* rightRotate(node* root){
    node *x,*y;
    x = root -> left;
    y = x -> right;

    x->right = root;
    root->left = y;

    root->h = getH(root);
    x->h = getH(x);

    return x;
}

node* leftRotate(node* root){
    node *x,*y;
    x = root -> right;
    y = x -> left;

    x->left = root;
    root->right = y;

    root->h = getH(root);
    x->h = getH(x);

    return x;
}

node* insert(node* root, int &val){
    if(root == NULL){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->val = val;
        newnode->h = 1;
        root = newnode;
        return root;
    }

    if(val <= root->val){
        root->left = insert(root->left, val);
    } else if(val > root->val){
        root->right = insert(root->right, val);
    }


    int lh=0, rh=0;
    if(root->left)
        lh = root->left->h;
    if(root->right)
        rh = root->right->h;
    root->h = max(lh,rh)+1;

    int bal = lh - rh;

    // rr rotate
    if( bal > 1 && val <= root->left->val){
        return rightRotate(root);
    }

    // lr
    if( bal > 1 && val > root->left->val){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // rl
    if( bal < -1 && val <= root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // ll
    if( bal < -1 && val > root->right->val){
        return leftRotate(root);
    }
    return root;
}

node* deleteAVL(node* root, int &val){
    if(root == NULL){
        cout<<val<<" Not Found!"<<endl;
        return NULL;
    }

    if(val < root->val){
        root->left = deleteAVL(root->left, val);
    } else if( val > root->val){
        root->right = deleteAVL(root->right, val);
    } else {
        if(root->left == NULL || root->right == NULL){
            if(root->left){
                return root->left;
            } else {
                return root->right;
            }
        } else {
            node *par = root,*temp;

            temp = root->left;
            while(temp->right){
                par = temp;
                temp = temp->right;
            }

            root->val = temp->val;
            root->left = deleteAVL(root->left, temp->val);
        }
    }

    int lh=0,rh=0;
    if(root->left)
        lh = root->left->h;
    if(root->right)
        rh = root->right->h;
    root->h = max(lh,rh)+1;

    int bal = lh-rh;

    // rr rotate
    if( bal > 1 && val <= root->left->val){
        return rightRotate(root);
    }

    // lr
    if( bal > 1 && val > root->left->val){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // rl
    if( bal < -1 && val <= root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // ll
    if( bal < -1 && val > root->right->val){
        return leftRotate(root);
    }
    return root;
}

void inorder(node *root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

int main(){

    while(1){
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Inorder"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice : ";

        int choice;
        int val;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value : ";
                cin>>val;
                root = insert(root,val);
            break;
            case 2:
                cout<<"Enter value : ";
                cin>>val;
                root = deleteAVL(root,val);
            break;
            case 3:
                inorder(root);
                cout<<endl;
            break;
            case 0:
                return 0;
            break;
            default:
                cout<<"Invalid input"<<endl;
        }

    }

}
