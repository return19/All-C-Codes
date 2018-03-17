#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n,h;
    int x;

    scanf("%d%d",&n,&h);
    int ans=0;

    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x>h)
            ans+=2;
        else
            ans++;
    }

    printf("%d\n",ans);

    return 0;
}
