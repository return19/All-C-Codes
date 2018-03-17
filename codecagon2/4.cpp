#include<bits/stdc++.h>
using namespace std;

int ride[3010][3010];
int taxi[3010][3010];
int dist_r[3010];
int dist_t[3010];
int vis_r[3010];
int vis_t[3010];
int n,m;

int main()
{
    int i,j,k;
    int test,t;
    int x,y;
    int r,t;
    int s,d;

    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++){
            dist_r[i]=INT_MAX;
            dist_t[i]=INT_MAX;
            vis_r[i]=0;
            vis_t[i]=0;
        }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                ride[i][j]=INT_MAX;
                taxi[i][j]=INT_MAX;
            }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&r,&t);

            x--;    y--;
            ride[x][y]=r;
            taxi[x][y]=t;
            ride[y][x]=r;
            taxi[y][x]=t;
        }

        scanf("%d%d",s,d);

        dist_r[s]=0;
        dist_t[s]=0;

        int mn_r;
        int mn_t;
        int idx_r;
        int idx_t;

        for(i=0;i<n;i++)
        {
            mn_r=INT_MAX;
            mn_t=INT_MAX;

            for(j=0;j<n;j++)
            {
                if(!vis_r[j])
                {
                    mn_r=min(mn_r,dist_r[j]);
                    idx_r=j;
                }
                if(!vis_t[j])
                {
                    mn_t=min(mn_t,dist_t[j]);
                }
            }

            if(mn_r!=INT_MAX)
            {

            }

            if(mn_t!=INT_MAX)
            {

            }
        }

    }

    return 0;
}













