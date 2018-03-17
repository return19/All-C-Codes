#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ans;

    scanf("%d",&n);

    while(n!=0)
    {
        ans=5+(n*(n-1)*3)/2+4*(n-1);

        printf("%d\n",ans);

        scanf("%d",&n);
    }

    return 0;
}
