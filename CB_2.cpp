#include<bits/stdc++.h>
using namespace std;

int dp[3010][3010];
int n,m;

char fk[3010],og[3010];

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

void init()
{
    int i,j,k;
    int ins,del,rep;

    for(i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }

    for(i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            ins=dp[i-1][j]+1;
            del=dp[i][j-1]+1;
            rep=dp[i-1][j-1]+(fk[i-1]!=og[j-1]);
            dp[i][j]=min2(ins,min2(del,rep));
        }
    }

}

int main()
{
    int test,i,j,k;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",og);
        scanf("%s",fk);
        m=strlen(og);
        n=strlen(fk);
        //cout<<m<<" "<<n<<endl;
        init();
        /*for(j=0;j<=n;j++)
        {
            for(k=0;k<=m;k++)
                cout<<dp[j][k]<<" ";
            cout<<endl;
        }*/
        //cout<<dp[n][m]<<endl;
        printf("%d\n",dp[n][m]);

    }

    return 0;
}
