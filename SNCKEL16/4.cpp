#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> g[61];

int solve(int x,int t)
{

}

int main()
{
    int i,j;
    int test,t;
    int x,y;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&k);

        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            x--;    y--;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans = solve(0,0);
    }
    return 0;
}
