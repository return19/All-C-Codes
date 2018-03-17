#include<bits/stdc++.h>
using namespace std;

int b[110];
int g[110];

int main()
{
    int i,j,k;
    int n,m;
    int bh=0;
    int gh=0;
    int t;

    scanf("%d%d",&n,&m);

    scanf("%d",&bh);

    for(i=0;i<bh;i++)
    {
        scanf("%d",&t);
        b[t]=1;
    }

    scanf("%d",&gh);

    for(i=0;i<gh;i++)
    {
        scanf("%d",&t);
        g[t]=1;
    }

    int f=1;
    int curb=0,curg=0;


    while(1)
    {
        if(curb==0 && curg==0 && f==0)
            break;

        if(curb==0 && curg==0)
            f=0;

        if(b[curb]==1 && g[curg]==0)
        {
            g[curg]=1;
            gh++;
            f=1;
        }
        else if(b[curb]==0 && g[curg]==1)
        {
            b[curb]=1;
            bh++;
            f=1;
        }

        curb= (curb+1)%n;
        curg= (curg+1)%m;

        if(bh==n && gh==m)
            break;
    }

    if(bh==n && gh==m)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
















