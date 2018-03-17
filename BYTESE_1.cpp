#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long arr[110][110];

set< pair<long long,pair<long long,long long> > > s;
set< pair<long long,pair<long long,long long> > >::iterator it;
 long long n,m;
long long move_x[4]={-1,1,0,0};
long long move_y[4]={0,0,1,-1};

long long check(long long x,long long y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

long long d[110][110];

int main()
{
    long long i,j,k;
    long long test,t;

    long long px,py,bt;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&m);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%lld",&arr[i][j]);

        scanf("%lld%lld%lld",&px,&py,&bt);
        px--;   py--;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(i!=0 || j!=0){
                    s.insert(mp(LLONG_MAX,mp(i,j)));
                    d[i][j]=LLONG_MAX;
                }
        s.insert(mp(arr[0][0],mp(0,0)));
        d[0][0]=arr[0][0];
        long long ans=0;
        while(1){
            it=s.begin();
            pair< long long,pair<long long,long long> > p=(*it);
            s.erase(it);
            long long val,x,y;
            val=p.ft;
            x=p.sd.ft;
            y=p.sd.sd;

           // cout<<x<<" "<<y<<" : "<<val<<endl;

            if(x==px && y==py){
                ans=val;
                break;
            }

            for(i=0;i<4;i++){
                long long tx,ty;
                tx=x+move_x[i];
                ty=y+move_y[i];
                if(!check(tx,ty))
                    continue;
                if(d[tx][ty] > val + arr[tx][ty])
                {
                    //cout<<tx<<" : "<<ty<<" ::"<<val+arr[tx][ty]<<endl;
                    s.erase(mp(d[tx][ty],mp(tx,ty)));
                    d[tx][ty]=val + arr[tx][ty];
                    s.insert(mp(d[tx][ty],mp(tx,ty)));
                }
            }
        }
        s.clear();
        if(ans<=bt){
            printf("YES\n%lld\n",bt-ans);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}












