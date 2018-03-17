#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k,n;

    double ans,p;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        ans=0;
        p=n;
        for(j=1;j<=n;j++)
        {
            ans=ans+p/j;
        }

        printf("%.2f\n",ans);
    }

    return 0;
}
