#include<bits/stdc++.h>
using namespace std;

int ans[110];

int main()
{
    int i,j,k;

    int n;

    scanf("%d",&n);

    for(i=1;i<110;i++)
    {
        ans[i]=ans[i-1] + i*i;

       // cout<<ans[i]<<endl;
    }

    while(n!=0)
    {
        printf("%d\n",ans[n]);

        scanf("%d",&n);
    }

    return 0;
}
