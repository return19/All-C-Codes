#include<bits/stdc++.h>
using namespace std;

int arr[1000100];
int dp[1000100][71];
int n;

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void prepros()
{
    int i,j,k;

    memset(dp,0,sizeof(dp));

    for(i=0;i<n;i++)
    {
        dp[i][0]=arr[i];
    }

    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<(j-1))<n;i++)
        {
            if(dp[i][j-1]>dp[i+(1<<(j-1))][j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i+(1<<(j-1))][j-1];
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;1<<j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}

int qry(int a,int b)
{
    int i,j,k;
    a--;
    b--;

    int sz=log(b-a+1)/log(2);

    int ans=max2(dp[a][sz],dp[b-(1<<sz)+1][sz]);

    return ans;
}

int main()
{
    int test,i,j,k;
    int ans;
    int q,a,b;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }

        prepros();

        scanf("%d",&q);

        for(j=0;j<q;j++)
        {
            scanf("%d%d",&a,&b);

            ans=qry(a,b);

            printf("%d\n",ans);
        }
    }

    return 0;
}











