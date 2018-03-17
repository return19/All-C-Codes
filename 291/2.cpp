#include<bits/stdc++.h>
using namespace std;

double arr[1010];
int vis[1010];

int main()
{
    int i,j,k;
    int n,x0,y0;
    int x,y;

    scanf("%d%d%d",&n,&x0,&y0);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);

        if(x-x0 == 0)
            arr[i]=INT_MAX;
        else
            arr[i]=(double)(y-y0)/(x-x0);
        //cout<<arr[i]<<endl;
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(vis[i])
            continue;
        ans++;
        vis[i]=1;

        for(j=i+1;j<n;j++)
        {
            if(!vis[j] && arr[j]==arr[i])
                vis[j]=1;
        }
    }

    printf("%d\n",ans);

    return 0;
}











