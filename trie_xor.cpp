#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* l;
    node *r;
    int cnt;

    node()
    {}

    node(node * left,node *right)
    {
        l=left;
        r=right;
        cnt=0;
    }

};

void trie_insert(node* head,int x,int level)
{
    if(level<0){
        head->cnt=1;
        return;
    }

   // cout<<"here"<<endl;
    int cur=(x>>level)&1;
    //cout<<cur<<endl;

    if(cur == 0)
    {
        if(head->l==NULL)
            head->l=new node(NULL,NULL);
        trie_insert(head->l,x,level-1);
    }
    else if(cur == 1)
    {
        if(head->r==NULL)
            head->r=new node(NULL,NULL);
        trie_insert(head->r,x,level-1);
    }

    head->cnt=0;
    if(head->l)
        head->cnt+=head->l->cnt;
    if(head->r)
        head->cnt+=head->r->cnt;
}

int trie_max_xor(node *head,int x,int level)
{
    if(level<0)
    {
        return 0;
    }

   // cout<<"xor"<<endl;

    int cur= (x>>level)&1;

    if(cur==0)
    {
        if(head->r != NULL)
        {
            return (1<<level) + trie_max_xor(head->r,x,level-1);
        }
        return trie_max_xor(head->l,x,level-1);
    }
    else // 1
    {
        if(head->l != NULL)
        {
            return (1<<level) + trie_max_xor(head->l,x,level-1);
        }
        return trie_max_xor(head->r,x,level-1);
    }
}



int main()
{
    node* head= new node(NULL,NULL);

    int i,j,k;
    int test,t;
    int n;
    int temp;
    int ans;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        ans=INT_MIN;

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            trie_insert(head,temp,31);

            ans=max(ans,trie_max_xor(head,temp,31));
        }

        printf("%d\n",ans);
    }





    return 0;
}




















