#include<bits/stdc++.h>
using namespace std;

int arr[1010];
int vis[1010];

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int cur=0;
    int ans=0;
    int d=0;
    i=0;

    while(cur!=n)
    {
        if( !vis[i] && arr[i]<=cur)
        {
            vis[i]=1;
            cur++;
        }

        if(cur==n)
            break;

        if(d==0)
            i++;
        else
            i--;

        if(i==n)
        {
            i=n-1;
            d=1-d;
            ans++;
        }else if(i==-1)
        {
            i=0;
            d=1-d;
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}

