#include<bits/stdc++.h>
using namespace std;

int r[51],c[51];

int main()
{
    int i,j,k;
    int n;
    int x,y;

    scanf("%d",&n);

    for(i=0;i<n*n;i++)
    {
        scanf("%d%d",&x,&y);

        if(r[x]==0 && c[y]==0)
        {
            r[x]=1;
            c[y]=1;
            printf("%d ",i+1);
        }
    }

    return 0;
}
