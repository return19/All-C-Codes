#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n;

    double ans,temp;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lf",&temp);

        ans += temp/n;
    }

    printf("%.4lf\n",ans);

    return 0;
}
