#include<bits/stdc++.h>
using namespace std;

vector<int> g[101000];
int vis[101000];
int n,m;

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        g[x].push_back(y);
    }



    return 0;
}
