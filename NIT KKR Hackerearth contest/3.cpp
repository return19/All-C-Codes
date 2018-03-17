#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

// just create par[] array and initialize it with -1
long long par[1010000];
long long root(long long v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(long long x,long long y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}



vector<pair<long long,long long> > v[101000];
vector< pair< long long,pair<long long,long long> > > e;
map< pair<long long,long long>,long long > memo;
map< pair<long long,long long>,long long >::iterator it;
long long n,m;

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;
    scanf("%lld",&test);

    for(t=0;t<test;t++){
        memo.clear();
        e.resize(0);
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++){
            scanf("%lld%lld",&x,&y);
            x--;    y--;
            memo[mp(min(x,y),max(x,y))]=0;
        }
        long long q;
        scanf("%lld",&q);
        for(i=0;i<q;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;    y--;
            if(memo.find(mp(min(x,y),max(x,y)))==memo.end()){
                memo[mp(min(x,y),max(x,y))] = z;
            }
        }

        for(it=memo.begin();it!=memo.end();it++){
          //  cout<<it->second<<" "<<it->first.ft<<" "<<it->first.sd<<endl;
            e.push_back(mp(it->second,it->first));
        }

        for(i=0;i<n;i++)
            par[i]=-1;


        sort(e.begin(),e.end());
        long long ans=0;
        for(i=0;i<e.size();i++){
            long long c = e[i].ft;
            x = e[i].sd.ft;
            y = e[i].sd.sd;
            if(root(x)!=root(y)){
                ans+=c;
                merge_dsu(x,y);
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}










