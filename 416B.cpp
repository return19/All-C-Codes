#include<bits/stdc++.h>
using namespace std;

long long fr[10];

long long arr[501000][10];

int main()
{
    long long m,n;
    long long i,j,k;


    scanf("%lld%lld",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[i][j]);
        }
    }

    fr[0]=arr[0][0];

    for(j=1;j<n;j++)
        fr[j]=fr[j-1] + arr[0][j];

    printf("%lld ",fr[n-1]);

    for(i=1;i<m;i++)
    {
        fr[0]=fr[0] + arr[i][0];

        for(j=1;j<n;j++)
        {
            fr[j]=max(fr[j-1],fr[j]) + arr[i][j];
        }
        printf("%lld ",fr[n-1]);
    }

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

long long fr[501000][10];

long long arr[501000][10];

int main()
{
    long long m,n;
    long long i,j,k;


    scanf("%lld%lld",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[i][j]);
        }
    }

    fr[0][0]=arr[0][0];

    for(j=1;j<n;j++)
        fr[0][j]=fr[0][j-1] + arr[0][j];

    printf("%lld ",fr[0][n-1]);

    for(i=1;i<m;i++)
    {
        fr[i][0]=fr[i-1][0] + arr[i][0];

        for(j=1;j<n;j++)
        {
            fr[i][j]=max(fr[i][j-1],fr[i-1][j]) + arr[i][j];
        }
        printf("%lld ",fr[i][n-1]);
    }

    return 0;
}












*/







