#include<bits/stdc++.h>
using namespace std;

vector<int> g[20010];

int gen[20010];
int n,ni;

int dfs(int i)
{
    int j,k,l;
    int ans=1;

    for(j=0;j<g[i].size();j++)
    {
        if(gen[g[i][j]]!=0)
        {
            if(gen[i]==gen[g[i][j]])
                return 0;
        }
        else
        {
            gen[g[i][j]]=-gen[i];
            ans=ans&&dfs(g[i][j]);
            if(ans==0)
                return 0;
        }
    }
    return ans;
}

int main()
{
    int test,i,j,k;
    int temp1,temp2,ans;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        ans=1;
        //memset(gen,0,sizeof(gen));


        scanf("%d%d",&n,&ni);

        for(j=0;j<n;j++)
        {
            g[j].clear();
            gen[j]=0;
        }

        for(j=0;j<ni;j++)
        {
           scanf("%d%d",&temp1,&temp2);
           temp1--;
           temp2--;
           g[temp1].push_back(temp2);
           g[temp2].push_back(temp1);
        }

        for(j=0;j<n;j++)
        {
            if(gen[j]==0)
            {
                gen[j]=1;
                ans=dfs(j);

                if(ans==0)
                {
                    break;
                }
            }
        }

        if(ans==0)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",i+1);
        }
        else
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",i+1);
        }
    }

    return 0;
}








