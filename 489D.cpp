#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

map< pair<long long,long long>,long long > ans;
map< pair<long long,long long>,long long >::iterator it;

vector<long long> to[3010];
vector<long long> from[3010];

int main()
{
    long long i,j,k;
    long long n,m;
    long long x,y;

    scanf("%lld%lld",&n,&m);
    for(i=0;i<m;i++){
        scanf("%lld%lld",&x,&y);
        x--;    y--;
        to[y].push_back(x);
        from[x].push_back(y);
    }

    for(i=0;i<n;i++){
        for(j=0;j<to[i].size();j++){
            for(k=0;k<from[i].size();k++){
                if(to[i][j] != from[i][k])
                    ans[mp(to[i][j],from[i][k])]++;
            }
        }
    }

    long long res=0;

    for(it=ans.begin();it!=ans.end();it++){
        res = res + (it->second)*(it->second -1)/2;
    }

    printf("%lld\n",res);

    return 0;
}


















