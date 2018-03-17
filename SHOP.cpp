#include<bits/stdc++.h>
using namespace std;

long long arr[30][30];

long long st_x,ed_x;
long long st_y,ed_y;

char str[30];

long long dist[30][30];
long long vis[30][30];

long long n,m;

long long check(long long x,long long y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return 1;
    return 0;
}

int main()
{
    long long i,j,k;

    scanf("%lld%lld",&m,&n);

    while(n!=0&&m!=0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vis[i][j]=0;

        for(i=0;i<n;i++)
        {
              scanf("%s",str);

              for(j=0;j<m;j++)
              {
                  if(str[j]=='S')
                  {
                      st_x=i;
                      st_y=j;

                      arr[i][j]=0;
                  }
                  else if(str[j]=='D')
                  {
                      ed_x=i;
                      ed_y=j;

                      arr[i][j]=0;
                  }
                  else if(str[j]=='X')
                  {
                      arr[i][j]=-1;
                  }
                  else
                    arr[i][j]=str[j]-'0';
              }
        }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                dist[i][j]=LLONG_MAX;

        dist[st_x][st_y]=0;

        long long mn=LLONG_MAX;
        long long mn_x,mn_y;

        for(i=0;i<n*m;i++)
        {
            mn=LLONG_MAX;

            for(j=0;j<n;j++)
            {
                for(k=0;k<m;k++)
                {
                    if(arr[j][k]!=-1 && !vis[j][k] && mn>dist[j][k])
                    {
                        mn=dist[j][k];
                        mn_x=j;
                        mn_y=k;
                    }
                }
            }

            if(mn==LLONG_MAX)
                break;

            long long x=mn_x;
            long long y=mn_y;

            vis[x][y]=1;

            if(check(x-1,y) && arr[x-1][y]!=-1 && !vis[x-1][y] )
                dist[x-1][y]=min(dist[x-1][y],dist[x][y] + arr[x-1][y]);


            if(check(x+1,y) && arr[x+1][y]!=-1 && !vis[x+1][y] )
                dist[x+1][y]=min(dist[x+1][y],dist[x][y] + arr[x+1][y]);


            if(check(x,y-1) && arr[x][y-1]!=-1 && !vis[x][y-1] )
                dist[x][y-1]=min(dist[x][y-1],dist[x][y] + arr[x][y-1]);


            if(check(x,y+1) && arr[x][y+1]!=-1 && !vis[x][y+1] )
                dist[x][y+1]=min(dist[x][y+1],dist[x][y] + arr[x][y+1]);
        }

        /*for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
                if(dist[j][k]!=LLONG_MAX)
                cout<<dist[j][k]<<" ";
                else
                    cout<<"X"<<" ";
            cout<<endl;
        }*/

        printf("%lld\n",dist[ed_x][ed_y]);

        scanf("%lld%lld",&m,&n);
    }

    return 0;
}













