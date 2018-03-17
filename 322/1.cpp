#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n,m;

    scanf("%d%d",&n,&m);
    int ans=min(n,m);

    if(n>m)
        swap(n,m);
    m-=n;

    printf("%d ",ans);
    ans=m/2;

    printf("%d\n",ans);
    return 0;
}
