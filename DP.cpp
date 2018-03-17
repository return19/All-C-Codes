#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

long long n,m;

char arr[61][61];
long long dist[61][61];
long long vis[61][61];
vector< pair<long long,long long> > build;
set< pair< long long,pair<long long,long long> > > s;
set< pair< long long,pair<long long,long long> > >::iterator it;
long long pdx,pdy;

long long move_x[10]={-1,1,0,0};
long long move_y[10]={0,0,-1,1};

long long check(long long x,long long y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

void dijkstra()
{
    long long i,j,k;

    s.clear();

    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            dist[i][j]=LLONG_MAX;
            vis[i][j]=0;

            if(!(i==pdx && j==pdy))
            {
                s.insert(mp(LLONG_MAX,mp(i,j)));
            }
        }
    dist[pdx][pdy]=0;
    s.insert(mp(0,mp(pdx,pdy)));

    while(!s.empty())
    {
        it=s.begin();
        long long val=it->ft;
        long long x=it->sd.ft;
        long long y=it->sd.sd;
        vis[x][y]=1;

       // cout<<val<<" "<<x<<" "<<y<<endl;

        if(val==LLONG_MAX)
            return;

        s.erase(mp(val,mp(x,y)));

        for(i=0;i<4;i++)
        {
            long long tx= x + move_x[i];
            long long ty= y + move_y[i];

            if(!check(tx,ty) || vis[tx][ty])
                continue;

            long long init=dist[tx][ty];

            if(arr[x][y]=='$' || arr[x][y]=='X')
            {
                dist[tx][ty]=min(dist[tx][ty],val+2);
            }
            else if(arr[tx][ty]!='$' && abs(arr[x][y] - arr[tx][ty])==0 )
            {
                dist[tx][ty]=min(dist[tx][ty],val+1);
            }
            else if(arr[tx][ty]!='$' && abs(arr[x][y] - arr[tx][ty])==1)
            {
                dist[tx][ty]=min(dist[tx][ty],val+3);
            }
            else if(arr[tx][ty]=='$')
            {
                dist[tx][ty]=min(dist[tx][ty],val+2);
            }

            if(dist[tx][ty]!=init)
            {
                s.erase(mp(init,mp(tx,ty)));
                s.insert(mp(dist[tx][ty],mp(tx,ty)));
            }
        }
    }
}

long long solve(long long idx,long long sum1,long long sum2,long long max1,long long max2)
{
    if(idx==build.size())
    {
        return max( sum1-max1,sum2-max2 );
    }

    long long tk1,tk2;
    long long d=dist[build[idx].ft][build[idx].sd];
    tk1=solve(idx+1,sum1+2*d,sum2,max(max1,d),max2);
    tk2=solve(idx+1,sum1,sum2+2*d,max1,max(max2,d));
    return min(tk1,tk2);
}

int main()
{
    long long test,t;
    long long i,j,k;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&m);
        build.resize(0);

        for(i=0;i<n;i++)
        {
            scanf("%s",arr[i]);

            for(j=0;j<m;j++)
            {
                if(arr[i][j]=='X')
                {
                    pdx=i;  pdy=j;
                }
                else if(arr[i][j]=='$')
                {
                    build.push_back(mp(i,j));
                }
            }
        }

        dijkstra();
        int f=0;
        for(i=0;i<build.size();i++)
        {
            if(dist[build[i].ft][build[i].sd]==LLONG_MAX)
            {
                f=1;
                break;
            }
        }

        if(f)
        {
            printf("-1\n");
            continue;
        }

       /* for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }*/

        long long ans=solve(0,0,0,0,0);

        printf("%lld\n",ans);
    }


    return 0;
}














