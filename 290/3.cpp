#include<bits/stdc++.h>
using namespace std;

char arr[1010][1010];
int n,m;
int vis[1010][1010];

int movex[10]={0,0,1,-1};
int movey[10]={1,-1,0,0};

int check(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int dfs(int x,int y,int px,int py)
{
    vis[x][y]=1;
   // cout<<x<<" : "<<y<<endl;

    int i,j,k;

    for(i=0;i<4;i++)
    {
        int tx= x + movex[i];
        int ty= y + movey[i];

        if(!check(tx,ty) || arr[tx][ty]!=arr[x][y] || (tx==px && ty==py))
            continue;

        if(vis[tx][ty]){
           // cout<<" t "<<tx<<" "<<ty<<endl;
            return 1;
        }

        if(dfs(tx,ty,x,y))
            return 1;
    }

    return 0;
}

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                int temp=dfs(i,j,-1,-1);
                if(temp)
                {
                   // cout<<i<<" "<<j<<endl;
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }

    printf("No\n");

    return 0;
}

