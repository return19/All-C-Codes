#include<bits/stdc++.h>
using namespace std;

char str[450];
char z[450];

long long arr[450];

long long n,m;

long long M=10000000007;

void inside(char str[],char z[])
{
    long long i,j,k;

    for(i=0;i<n;i++)
    {
        if(str[i]==z[0])
        {
            for(j=i; j<n && j<i+m ;j++)
            {
                if(str[j]!=z[j-i])
                    break;
            }

            if(j==i+m)
            {
                arr[i]=1;
            }
            else
                arr[i]=0;
        }
        else
            arr[i]=0;
    }

}

long long c;

long long memo[500][500];

long long solve(long long idx,long long x)
{

    long long i,j,k;

    if(x==0)
        return 1;

      if(idx>=n)
        return 0;

    if(memo[idx][x]!=-1)
      return memo[idx][x];

    long long ans=0;



    long long l=n+1;
    long long temp;

     long long en;

    for(i=idx;i<n;i++)
    {
        en=0;
        for(j=i;j<=n;j++)
        {
            if(j<n&&arr[j]==1&&en==0)
            {
                en=1;
                j=j+m;
                j--;
                continue;
            }

            if(en==1)
            {
                ans = (ans + solve(j,x-1))%M;
            }
        }
    }

    return memo[idx][x]=ans;
}

int main()
{
    long long i,j,k;

    long long test,t;

    long long ans=0;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {

        scanf("%s",str);
        scanf("%s",z);

        n=strlen(str);
        m=strlen(z);

        for(i=0;i<=n+10;i++)
            for(j=0;j<=n+10;j++)
                memo[i][j]=-1;

        inside(str,z);

        ans=0;

        for(i=1;i<=n/m+1;i++)
        {
            ans = (ans + solve(0,i))%M;
        }

        printf("%lld\n",ans);

        /*for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                cout<<memo[i][j]<<" ";
            }
            cout<<endl;
        }*/

        //cout<<c<<endl;

    }

    return 0;
}



