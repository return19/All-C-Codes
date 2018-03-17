#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,n,k,ans,temp;

   scanf("%d%d",&n,&k);

    while(n!=0&&k!=0)
    {


        ans=1;
        for(j=1;j<=n;j++)
        {
            ans=(ans+k-1)%j+1;
        }

        printf("%d %d %d\n",n,k,ans);

        scanf("%d%d",&n,&k);
    }

    return 0;
}
