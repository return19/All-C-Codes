#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;
    int n;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);

        int ans=-1;
        int t;
        for(j=1;j<=k;j++)
        {
            t=n%j;

            ans=max(ans,t);
        }

        printf("%d\n",ans);
    }

    return 0;
}
