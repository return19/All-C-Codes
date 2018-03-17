#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* l;
    node *r;
    long long cnt;

    node()
    {}

    node(node * left,node *right)
    {
        l=left;
        r=right;
        cnt=0;
    }

};

void trie_insert(node* head,long long x,long long level)
{
    if(level<0){
        head->cnt += 1;
        return;
    }

   // cout<<"here"<<endl;
    long long cur=(x>>level)&1;
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
        head->cnt += head->l->cnt;
    if(head->r)
        head->cnt += head->r->cnt;
}

long long trie_max_xor(node *head,long long x,long long level)
{
    if(level<0)
    {
        return 0;
    }

   // cout<<"xor"<<endl;

    long long cur= (x>>level)&1;

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

long long trie_k(node* head,long long x,long long level,long long k)
{
    if(level<0)
        return 0;

    long long cur=(x>>level)&1;
    long long curk=(k>>level)&1;

    if(curk==0)
    {
        if(cur==0){

            if(head->l)
                return trie_k(head->l,x,level-1,k);
            return 0;
        }

        if(head->r)
            return trie_k(head->r,x,level-1,k);
        return 0;
    }
    else // k==1
    {
        long long temp=0;
        if(cur==0){
            if(head->l)
                temp=head->l->cnt;
            if(head->r)
                return temp + trie_k(head->r,x,level-1,k);
            return temp;
        }

        if(head->r)
            temp=head->r->cnt;
        if(head->l)
            return temp + trie_k(head->l,x,level-1,k);
        return temp;

    }
}

int main()
{
    node* head;

    long long i,j,k;
    long long test,t;
    long long n;
    long long temp;
    long long ans;
    long long pre=0;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        head= new node(NULL,NULL);
        trie_insert(head,0,31); // tricky thing

        scanf("%lld%lld",&n,&k);
        ans=0;
        pre=0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp);
            pre = pre^temp;
            ans += trie_k(head,pre,31,k);
            trie_insert(head,pre,31);
        }

        printf("%lld\n",ans);
    }





    return 0;
}



















