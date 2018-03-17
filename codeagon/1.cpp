#include<bits/stdc++.h>
using namespace std;

long long arr[11000];
long long nc[11000];

int main()
{
    long long i,j,k;
    long long n,m;

    scanf("%lld%lld",&n,&m);

    arr[0]=1;
    nc[0]=0;

    for(i=1;i<=m;i++)
    {
        nc[i]=99999999999;
    }

    for(i=1;i<=n;i++)
    {
        for(j=m;j>0;j--)
        {
            if(j-i<0)
                break;

            if(arr[j-i]==1&&nc[j]>nc[j-i]+1)
            {
                arr[j]=1;
                nc[j]=nc[j-i]+1;
            }
        }
    }

    printf("%lld\n",nc[m]);



    return 0;
}
