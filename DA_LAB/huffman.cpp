#include<bits/stdc++.h>
using namespace std;

int arr[10100];

typedef struct a
{
    int val;
    struct a *left;
    struct a *right;
}elem;

class mycomparison
{
public:

    bool operator() (elem *a,elem *b)
    {
        if(a->val>b->val)
            return true;
        return false;
    }
};


priority_queue< elem*,vector< elem* >,mycomparison > pq;

void inorder(elem *root,vector<int> &v)
{
    if(root)
    {
        v.push_back(0);
        inorder(root->left,v);
        v.pop_back();

        if(!root->left && !root->right){
            cout<<root->val<<" : ";
            for(int i=0;i<v.size();i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }

        v.push_back(1);
        inorder(root->right,v);
        v.pop_back();
    }

}

int main()
{
    int i,j,k;

    int n;

    elem *x,*y,*z;

    cin>>n;

    for(i=0;i<n;i++){

        cin>>arr[i];

        x=NULL;

        x=(elem*)malloc(sizeof(elem));

        x->val=arr[i];
        x->left=NULL;
        x->right=NULL;

        pq.push(x);

    }



    for(i=0;i<n-1;i++)
    {
        x=pq.top();
        pq.pop();

        y=pq.top();
        pq.pop();



        z=(elem*)malloc(sizeof(elem));

        z->val= x->val + y->val;

        z->left=x;
        z->right=y;

        pq.push(z);
    }

    z=pq.top();
    pq.pop();

    vector<int> v;
    inorder(z,v);


    return 0;
}








