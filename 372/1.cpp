#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n;
    int x;

    scanf("%d%d",&n,&k);

    int ans=1;
    int prev = -1;

    for(i=0;i<n;i++){
        scanf("%d",&x);

        if(prev!=-1)
        {
            if(abs(prev-x) > k)
                ans=1;
            else
                ans++;
        }
        prev = x;

    }

    printf("%d\n",ans);

    return 0;
}
