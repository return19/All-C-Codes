#include<bits/stdc++.h>
using namespace std;

char str[110];

char arr[110][110];
int tb[110][110];

int visited[110][110];
int n,m;

int move_x[10]={0,-1,-1,-1,0,1,1,1};
int move_y[10]={-1,-1,0,1,1,1,0,-1};

int max1;
int count1=0;

int abs1(char a,char b)
{
    int i=a-b;
    if(i>=0)
        return i;
    else
        return -1*i;
}

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int dfs(int x,int y)
{
    int i,j,k;
    int tempx,tempy;

    int max1=0;

    visited[x][y]=1;
    tb[x][y]=0;

    for(i=0;i<8;i++)
    {
        tempx=x+move_x[i];
        tempy=y+move_y[i];

        if(tempx>=0&&tempx<n&&tempy>=0&&tempy<m)
        {
            if(arr[tempx][tempy]-arr[x][y]==1)
            {
                if(!visited[tempx][tempy])
                    tb[x][y]=max2(tb[x][y],1+dfs(tempx,tempy));
                else
                    tb[x][y]=max2(tb[x][y],1+tb[tempx][tempy]);
            }
        }
    }

    return tb[x][y];

}

int main()
{
    int i,j,k;
    int z=1;
    scanf("%d%d",&n,&m);

    while(n!=0&&m!=0)
    {
        memset(visited,0,sizeof(visited));
        memset(tb,0,sizeof(tb));
        max1=0;

        for(i=0;i<n;i++)
        {
            scanf("%s",str);

            for(j=0;j<m;j++)
            {
                arr[i][j]=str[j];
            }
        }
        max1=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]=='A'&&tb[i][j]==0)
                {
                    //memset(visited,0,sizeof(visited));
                    max1=max2(max1,dfs(i,j));
                }
            }
        }

        max1++;
        printf("Case %d: %d\n",z++,max1);

        scanf("%d%d",&n,&m);
    }

    return 0;
}
