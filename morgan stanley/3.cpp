#include<bits/stdc++.h>
using namespace std;

long long prnt[201000];

long long pq[201000];

long long arr[201000];

long long id[201000];

long long n;
//disjoint set template
//highly volatile
//change according to question

long long find_it(long long x)
{
    if(prnt[x]==x)
    {
        return x;
    }
    else
    {
        return prnt[x]=find_it(prnt[x]);
    }
}

void union_it(long long x,long long y)
{
    long long i,j,k;

    i=find_it(x);
    j=find_it(y);

    if(i==j)
    {

        //prnt[y]=x;
        //return y;
    }

    prnt[y]=x;
}

void percolate_down(long long idx)
{
    long long i,j,k;

    long long temp;

    long long min1=idx;


    if(2*idx<=n)
    {
        if(arr[pq[min1]]>arr[pq[2*idx]])
            min1 = 2*idx;
    }

    if(2*idx+1<=n)
    {
        if( arr[pq[min1]] > arr[pq[2*idx+1]] )
            min1=2*idx+1;
    }

    if(min1==idx)
    {
        //do something if required
        //else leave empty
    }
    else
    {
        id[pq[idx]]=min1;
        id[pq[min1]]=idx;
        temp=pq[idx];
        pq[idx]=pq[min1];
        pq[min1]=temp;
        percolate_down(min1);
    }
}

int main()
{
    long long i,j,k;

    long long px,py;
    long long y,z;

    long long temp;
    long long q;

    scanf("%lld%lld",&n,&q);

    for(i=1;i<=n;i++){

        scanf("%lld",&arr[i]);
    }

    for(i=1;i<=n;i++)
    {
        pq[i]=i;
        prnt[i]=i;
        id[i]=i;
    }

    for(i=n/2;i>0;i--)
    {
        percolate_down(i);
    }

    for(i=1;i<=q;i++)
    {
        scanf("%lld%lld",&y,&z);

        py=find_it(z);

        px=find_it(y);

        if(px!=py)
        {
            temp=arr[py];

            arr[py]=LLONG_MAX;

            percolate_down(id[py]);

            arr[px]+=temp;
            percolate_down(id[px]);

            union_it(px,py);
        }

        printf("%lld\n",arr[pq[1]]);
    }



    return 0;
}









