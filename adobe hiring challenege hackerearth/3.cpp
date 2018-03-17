#include<bits/stdc++.h>
using namespace std;

map< int,pair<int,int> > memo;

int main()
{
    int i,j,k;
    int n,m;
    int x,q;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&x);
            memo[x]=make_pair(i,j);
        }
    }

    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&x);
        if(memo.find(x)==memo.end())
            printf("-1 -1\n");
        else
            printf("%d %d\n",memo[x].first,memo[x].second);
    }

    return 0;
}
