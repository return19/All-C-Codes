#include<bits/stdc++.h>
using namespace std;

int ax[101000];
int ay[101000];

int main()
{
    int i,j,k;
    int test,t;
    int x,y;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d%d",&n,&m,&q);

        ax[1]=1;
        ay[1]=1;

        ax[n]=1;
        ay[m]=1;

        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);

            ax[x]=1;
            ay[y]=1;
        }
        int xc=0,yc=0;

        for(i=1;i<n;i++)
            if(ax[i]==1)
                xc++;
        for(i=1;i<m;i++)
            if(ay[i]==1)
                yc++;

        int j=1,k=1;
        int mnx=0;

        for(i=2;i<=n;i++)
        {
            if(ax[i]==1)
            {
                mnx=min(mnx,i-j)
            }
        }
    }

    return 0;
}













