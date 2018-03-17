#include<bits/stdc++.h>
using namespace std;


int n,m;

int arr[110];

int dp[110][20010];

int opr[110][20010];

int a[110];


void solve_dp()
{
    int i,j,k;

    int x=10000;

    dp[1][arr[1]+x]=1;

    for(i=2;i<=n;i++)
    {
        for(j=0;j<=2*x+5;j++)
        {
            if(i>2&&j-arr[i]>=0&&dp[i-1][j-arr[i]])
            {
                dp[i][j]=1;
                opr[i][j]=1;//for +
            }

            if(j+arr[i]<=20005&&dp[i-1][j+arr[i]])
            {
                dp[i][j]=1;
                opr[i][j]=2;//for -
            }
        }
    }


    j=m+x;
    for(i=n;i>1;i--)
    {
        a[i-1]=opr[i][j];
        if(opr[i][j]==1)
        {
            j=j-arr[i];
        }
        else
        {
            j=j+arr[i];
        }
    }

    int c=0;
    for(i=1;i<n;i++)
    {
        if(a[i]==2)
            c++;
        else
            printf("%d\n",c+1);
    }

    while(c)
    {
        printf("1\n");
        c--;
    }


}

int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(dp,0,sizeof(dp));
        memset(opr,0,sizeof(opr));

        memset(a,0,sizeof(a));

        scanf("%d%d",&n,&m);

        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }

        solve_dp();
        printf("\n");
    }

    return 0;
}















