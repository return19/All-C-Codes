#include<bits/stdc++.h>
using namespace std;

long long vis[10][10];

long long dist[10][10];

long long a,b,c,d;

long long move_x[10]={-2,-2,2,2,-1,-1,1,1};
long long move_y[10]={-1,1,-1,1,-2,2,2,-2};

long long check(long long x,long long y)
{
    if(x>=0&&x<=7&&y>=0&&y<=7)
        return 1;
    return 0;
}
/*
long long solve(long long x,long long y)
{
    long long i,j,k;

    if(x==c && y==d)
    {
        cout<<"here"<<endl;
        return 0;

    }

    cout<<x<<" "<<y<<endl;
    long long temp;
    cin>>temp;

    vis[x][y]=1;

    long long tx,ty;

    long long ans=99999999;

    for(i=0;i<8;i++)
    {
        tx = x + move_x[i];
        ty = y + move_y[i];

        if( !check(tx,ty))
            continue;

        if(vis[tx][ty])
            continue;

        ans=min(ans , x*tx + y*ty + solve(tx,ty));
    }

    vis[x][y]=0;

    return ans;

}
*/

int main()
{
    long long i,j,k;

    long long mn;
    long long mnx,mny;

    while(scanf("%lld",&a)!=EOF)
    {
        scanf("%lld%lld%lld",&b,&c,&d);

        for(i=0;i<=8;i++)
            for(j=0;j<=8;j++){
                vis[i][j]=0;
                dist[i][j]=LLONG_MAX;
            }

        dist[a][b]=0;


        for(i=0;i<64;i++)
        {
            mn=LLONG_MAX;

            for(j=0;j<8;j++)
            {
                for(k=0;k<8;k++)
                {
                    if( !vis[j][k] && mn>dist[j][k])
                    {
                        mn=dist[j][k];
                        mnx=j;
                        mny=k;
                    }
                }
            }

            if(mn==LLONG_MAX)
                break;

            vis[mnx][mny]=1;

            long long x,y;

            for(j=0;j<8;j++)
            {
                x=mnx + move_x[j];
                y=mny + move_y[j];

                if( !check(x,y))
                    continue;

                if(vis[x][y])
                    continue;

                dist[x][y] = min(dist[x][y] , x*mnx + y*mny + mn);
            }
        }

        if(dist[c][d]==LLONG_MAX)
            printf("-1\n");
        else
            printf("%lld\n",dist[c][d]);

    }

    return 0;
}







