#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
vector< pair<int,double> > v[101000];
set< pair<double,int> > s;
int vis[101000];
double d[101000];

double solve(){
    int i,j,k;

    for(i=1;i<n;i++){
        s.insert(mp(0L,i));
        d[i]=0L;
        vis[i]=0;
    }
    s.insert(mp(-1,0));
    d[0]=-1;
    vis[0]=0;

    while(!s.empty()){
        set< pair<double,int> >::iterator it=s.begin();
        pair<double,int> p = *(it);
        s.erase(p);
        int x;
        double val;
        x=p.sd;
        val=p.ft;
        vis[x]=1;

        if(val==0)  return 0;

        for(i=0;i<v[x].size();i++){
            if(!vis[v[x][i].ft] && d[v[x][i].ft] > val*v[x][i].sd){
                s.erase(mp(d[v[x][i].ft],v[x][i].ft));
                d[v[x][i].ft]=val*v[x][i].sd;
                s.insert(mp(d[v[x][i].ft],v[x][i].ft));
            }
        }
    }
    return d[n-1];
}

int main()
{
    int i,j,k;
    int x,y;
    double z;
    scanf("%d",&n);

    while(n!=0){
        scanf("%d",&m);

        for(i=0;i<n;i++)
            v[i].resize(0);

        for(i=0;i<m;i++)
        {
            scanf("%d%d%lf",&x,&y,&z);
            x--;    y--;
            z/=100;
            v[x].push_back(mp(y,z));
            v[y].push_back(mp(x,z));
        }

        double ans=solve();
        printf("%0.6lf percent\n",-1*ans*100);
        scanf("%d",&n);
    }
    return 0;
}
