#include<bits/stdc++.h>
using namespace std;

int n;

int graph[2010][2010];

int visited[2010];

int start1[2010],START1=-1;
int val1[2010];
int val2[2010];

int dp[2010][2010];

int sol[2010];
int y[2010];

int abs1(int x)
{
    if(x>=0)
        return x;
    return (-1)*x;
}

void dfs(int x,int t)
{
    int i,j,k;

    visited[x]=1;

    if(t==0)
    {
        val1[START1]++;
    }
    else
    {
        val2[START1]++;
    }

    for(i=0;i<n;i++)
    {
        if(graph[x][i]&&!visited[i])
        {
            if(t==0)
            {
                dfs(i,1);
            }
            else
            {
                dfs(i,0);
            }
        }
    }

}

void solve_dp()
{
    int i,j,k;
    int n1=START1;

    dp[0][0]=1;

    for(i=1;i<=n;i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }

    for(i=1;i<=n1+1;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dp[i][j]||(j-val1[i-1]>=0&&dp[i-1][j-val1[i-1]])||(j-val2[i-1]>=0&&dp[i-1][j-val2[i-1]]))
            {
                dp[i][j]=1;
            }
        }
    }
    cout<<"dp res : "<<endl;
    for(i=0;i<=n1+1;i++)
    {
        for(j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    int min_idx=99999999999;
    int min_val=99999999999;

    for(j=0;j<=n;j++)
    {
        if(dp[n1+1][j]&&min_val>abs1(j-n/2))
        {
            min_val=abs1(j-n/2);
            min_idx=j;
        }
    }

    cout<<"m_idx : "<<min_idx<<endl;
    cout<<"m_val : "<<min_val<<endl;
    j=min_idx;
    for(i=n1+1;i>0;i--)
    {
        if(dp[i-1][j-val1[i-1]])
        {
            sol[i-1]=1;
            j=j-val1[i-1];
        }
        else
        {
            sol[i-1]=2;
            j=j-val2[i-1];
        }

    }
    cout<<"sol : "<<endl;
    for(j=0;j<=n1;j++)
        cout<<sol[j]<<" ";
    cout<<endl;

}

void dfs2(int x,int t)
{
    int i,j,k;

    visited[x]=1;

    y[x]=t;

    for(i=0;i<n;i++)
    {
        if(!visited[i]&&graph[x][i])
        {
            if(t==0)
            {
                dfs2(i,1);
            }
            else
            {
                dfs2(i,0);
            }
        }
    }
}

int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                scanf("%d",&graph[j][k]);

        START1=-1;

        for(j=0;j<n;j++)
        {
            if(!visited[j])
            {
                start1[++START1]=j;
                dfs(j,0);
            }
        }
        cout<<"dfs res : "<<endl;
        for(j=0;j<=START1;j++)
            cout<<start1[j]<<" ";
        cout<<endl;

        for(j=0;j<=START1;j++)
            cout<<val1[j]<<" ";
            cout<<endl;
        for(j=0;j<=START1;j++)
            cout<<val2[j]<<" ";
            cout<<endl<<endl;

        solve_dp();

        memset(visited,0,sizeof(visited));

        for(j=0;j<=START1;j++)
        {
            if(sol[j]==1)
            {
                dfs2(start1[j],0);
            }
            else
            {
                dfs2(start1[j],1);
            }
        }

        for(j=0;j<n;j++)
            printf("%d ",y[j]);
        printf("\n");

    }

    return 0;
}

















