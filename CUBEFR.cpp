#include<bits/stdc++.h>
using namespace std;

int s[1000100];
int s_cum[1000100];

void sieve()
{
    int i,j,k,p;
    s[1]=0;

    for(i=2;i<=100;i++)
    {
        j=i*i*i;
        p=1;

        for(k=j;k<=1000010;k=j*p)
        {
            s[k]=1;
            s_cum[k]=1;
            p++;
        }
    }

    for(i=2;i<1000010;i++)
    {
        s_cum[i]+=s_cum[i-1];
    }
}

int main()
{
    int test,i,j,k;
    int n;

    sieve();

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        if(s[n]==1)
        {
            printf("Case %d: Not Cube Free\n",i+1);
        }
        else
        {
            printf("Case %d: %d\n",i+1,n-s_cum[n]);
        }
    }

    return 0;
}
