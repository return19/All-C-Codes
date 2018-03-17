#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long p,w,q;

map< string,long long > idx;
map< pair<long long,long long>,long long > worm;
vector< pair< pair<long long,long long>,long long > > v;

double dist[61][61];

void fw()
{
    long long i,j,k;

    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else{
                if(worm.find(mp(i,j))!=worm.end())
                    dist[i][j]=0;
                else
                    dist[i][j]=(sqrt(pow(v[i].ft.ft-v[j].ft.ft,2) + pow(v[i].ft.sd-v[j].ft.sd,2) + pow(v[i].sd-v[j].sd,2)));
            }
        }
    }

    for(k=0;k<p;k++)
    {
        for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    long long i,j,k;
    long long test,t;
    string s,s1;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        idx.clear();
        worm.clear();
        v.resize(0);

        scanf("%lld",&p);

        for(i=0;i<p;i++)
        {
            cin>>s;
            idx[s]=i;
            scanf("%lld%lld%lld",&x,&y,&z);
            v.push_back(mp(mp(x,y),z));
        }
        scanf("%lld",&w);
        for(i=0;i<w;i++)
        {
            cin>>s; x=idx[s];
            cin>>s; y=idx[s];
            worm[mp(x,y)]=1;
        }

        fw();

       /* for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }*/

        scanf("%lld",&q);
        printf("Case %lld:\n",t+1);
        for(i=0;i<q;i++)
        {
            cin>>s; x=idx[s];
            cin>>s1; y=idx[s1];
            cout<<"The distance from "<<s<<" to "<<s1<<" is "<<(long long)round(dist[x][y])<<" parsecs.\n";
        }
    }
    return 0;
}














