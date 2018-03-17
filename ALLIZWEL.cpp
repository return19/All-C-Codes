#include<bits/stdc++.h>
using namespace std;

char str[15]="ALLIZZWELL";

int n,m;

char arr[110][110];

char s[110];

int vis[110][110];

int move_x[10]={0,-1,-1,-1,0,1,1,1};
int move_y[10]={-1,-1,0,1,1,1,0,-1};

int check(int x,int y)
{
    if(x>=0 && x<n && y>=0 &&y<m)
            return 1;
    return 0;
}

int dfs(int x,int y,int idx)
{
    if(idx==9)
        return 1;

    vis[x][y]=1;

    //cout<<x<<" "<<y<<" "<<idx<<endl;

    int i,j,k;
    int tx,ty;

    for(i=0;i<8;i++)
    {
        tx= x + move_x[i];
        ty= y + move_y[i];

        if( !check(tx,ty) || vis[tx][ty] )
            continue;

        if(str[idx+1]==arr[tx][ty])
            if(dfs(tx,ty,idx+1))    return 1;
    }

    vis[x][y]=0;

    return 0;

}

int main()
{
    int test,i,j,k,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
        {
            scanf("%s",s);

            for(j=0;j<m;j++)
            {
                arr[i][j]=s[j];
            }
        }

        int ans=0;
        int temp;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vis[i][j]=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]=='A')
                {
                    temp=dfs(i,j,0);

                    if(temp==1)
                    {
                        ans=1;
                        break;
                    }
                }
            }

            if(ans==1)
                break;
        }

        if(ans==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
