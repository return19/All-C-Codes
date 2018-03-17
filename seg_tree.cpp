#include<bits/stdc++.h>
using namespace std;
#define MAX 9999999
int arr[10010],n;
int st[100010];
int qry(int ss,int se,int qs,int qe,int index);
int construct(int ss,int se,int index);

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int qry(int ss,int se,int qs,int qe,int index)
{
    if(qs>se||qe<ss)
        return MAX;
    if(ss>=qs&&se<=qe)
        return st[index];
    int mid=(ss+se)/2;
    return min2(qry(ss,mid,qs,qe,2*index+1),qry(mid+1,se,qs,qe,2*index+2));
}

int construct(int ss,int se,int index)
{
    if(ss==se)
    {
        st[index]=arr[ss];
    }
    else
    {
        int mid=(ss+se)/2;
        st[index]=min2(construct(ss,mid,2*index+1),construct(mid+1,se,2*index+2));

    }
    return st[index];
}

int main()
{
    int test,i,j,k,q,n;
    int a,b;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        construct(0,n-1,0);

        for(j=0;j<2*pow(2,(ceil(log2(n))))-1;j++)
            cout<<st[j]<<" ";
        cout<<endl;

        scanf("%d",&q);


        for(j=0;j<q;j++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",qry(0,n-1,a-1,b-1,0));
        }
    }

    return 0;
}

