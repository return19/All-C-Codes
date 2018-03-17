#include<bits/stdc++.h>
using namespace std;

//segmentation fault

struct node
{
    vector<int> v;

    node* l;
    node* r;

public:
    node()
    {
        l=NULL;
        r=NULL;
        vector<int> x;
        v=x;
    }

};

node* head=NULL;

int arr[601000];

vector<int> reverse_x(int x)
{
    int i,j;
    vector<int> v;

    for(i=0;i<20;i++)
    {
        if(x&1)
        {
            v.push_back(1);
        }
        else
            v.push_back(0);

        x=x>>1;
    }

    for(i=0,j=19;i<j;i++,j--)
    {
        swap(v[i],v[j]);
    }
    return v;
}

void insert_trie(int x,int idx)
{
    int i,j,k;
    node *temp=head;
    node *newnode;

    vector<int> tp;

    vector<int> v=reverse_x(x);

    for(i=0;i<20;i++)
    {
        if(v[i]==1)
        {
            if(temp->r==NULL)
            {
                temp->r= new node();
            }
            temp=temp->r;
            (temp->v).push_back(idx);
        }
        else
        {
            if(temp->l==NULL)
            {
                temp->l=new node();
            }
            temp=temp->l;
            (temp->v).push_back(idx);
        }
    }
}

int max_xor(int x,int l,int r)
{
    int i,j,k;
    vector<int> v=reverse_x(x);
    node* temp=head;
    for(i=0;i<20;i++)
    {
        if(v[i]==0){
            if(temp->r!=NULL&&upper_bound((temp->r)->v.begin(),(temp->r)->v.end(),r)-lower_bound((temp->r)->v.begin(),(temp->r)->v.end(),l)>=1)
            {
                temp=temp->r;
            }
            else
            {
                temp=temp->l;
            }
        }
        else
        {
            if(temp->l!=NULL&&upper_bound((temp->l)->v.begin(),(temp->l)->v.end(),r)-lower_bound((temp->l)->v.begin(),(temp->l)->v.end(),l)>=1)
            {
                temp=temp->l;
            }
            else
            {
                temp=temp->r;
            }
        }
    }
    return arr[(temp->v)[0]];
}

void remove_trie(int x)
{
    int i,j,k;
    node* temp=head;
    node *next;
    vector<int> v=reverse_x(x);

    for(i=0;i<20;i++)
    {
        next=temp;
        if(v[i]==1)
        {
            temp=temp->r;
            (temp->v).pop_back();
        }
        else
        {
            temp=temp->l;
            (temp->v).pop_back();
        }

        if((next->v).size()==0)
            delete next;
    }

    delete temp;
}

int lessthan(int x,int l,int r)
{
    int i,j,k;
    vector<int> v=reverse_x(x);
    int ans=0;

    node *temp=head;
    node *next;

    for(i=0;i<20;i++)
    {
        if(v[i]==0)
        {
            if(temp->l==NULL)
                return ans;
            temp=temp->l;
        }
        else
        {
            next=temp->l;
            if(next!=NULL)
                ans+=upper_bound((next->v).begin(),(next->v).end(),r)-lower_bound((next->v).begin(),(next->v).end(),l);
            temp=temp->r;

            if(temp==NULL)
                return ans;
        }
    }

    if(arr[(temp->v)[0]<=x])
        ans++;
    return ans;
}

int kths(node *head,int l,int r,int k)
{
    if(head->l==NULL && head->r==NULL)
        return arr[(head->v)[0]];

    int num=0;

    if(head->l!=NULL)
        num=upper_bound((head->l)->v.begin(),(head->l)->v.end(),r)-lower_bound((head->l)->v.begin(),(head->l)->v.end(),l);

    if(num>=k)
        return kths(head->l,l,r,k);
    else
        return kths(head->r,l,r,k-num);
}

int main()
{
    int i,j,k;
    int m;
    int x,y,z;
    int t;
    int n=0;

    head=(node*)malloc(sizeof(node));
    head->l=NULL;
    head->r=NULL;

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%d",&t);

        if(t==0)
        {
            scanf("%d",&x);

            insert_trie(x,n);
            arr[n]=x;
            n++;
        }
        else if(t==1)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            printf("%d\n",max_xor(z,x,y));
        }
        else if(t==2)
        {
            scanf("%d",&x);

            for(j=0;j<x;j++)
            {
                remove_trie(arr[n-1]);
                n--;
            }
        }
        else if(t==3)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;

            printf("%d\n",lessthan(z,x,y));
        }
        else if(t==4)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;

            printf("%d\n",kths(head,x,y,z));
        }
    }

    return 0;
}
