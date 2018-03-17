#include<bits/stdc++.h>
using namespace std;

map<int,int> memo;

int main()
{
    int i,j,k;
    int n,m;
    int x;
    int y;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);

        for(j=0;j<x;j++)
        {
            scanf("%d",&y);
            memo[y]=1;
        }
    }

    for(i=1;i<=m;i++)
    {
        if(memo[i]==0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
