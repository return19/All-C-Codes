#include<bits/stdc++.h>
using namespace std;

char str[101000];

int main()
{
    int i,j,k;
    int n;
    int x,y;
    int ans=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",str);
        scanf("%d%d",&x,&y);

        if(x>=2400 && (y-x)>0)
            ans=1;
    }

    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
