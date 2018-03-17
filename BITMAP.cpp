#include<bits/stdc++.h>
using namespace std;
#define MAX 99999999

long long arr[190][190];
long long dist[190][190];
long long n,m;

void init()
{
    long long i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j])
            {
                dist[i][j]=0;
            }
            else
                dist[i][j]=MAX;
        }
    }
}
long long get_d(long long x1,long long y1)
{
    if(x1>y1)
        return (x1-y1);
    else
        return (y1-x1);
}

void update(long long x,long long y)
{
    long long i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(dist[i][j]>(get_d(i,x)+get_d(j,y)))
            {
                dist[i][j]=get_d(i,x)+get_d(j,y);
            }
        }
    }
}

int main()
{
    long long test,i,j,k,num;
    //cin>>test;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        //cin>>n;
        //cin>>m;
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(j=0;j<n;j++)
        {
            //cin>>num;
            scanf("%lld",&num);
            for(k=m-1;k>=0;k--)
            {
                arr[j][k]=num%10;
                num=num/10;
            }
        }
         init();
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(arr[j][k])
                {
                    update(j,k);
                }
            }
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
               // cout<<dist[j][k]<<" ";
               printf("%lld ",dist[j][k]);
            }
            //cout<<endl;
            printf("\n");
        }
    }
}


















