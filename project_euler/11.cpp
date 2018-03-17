#include<bits/stdc++.h>
using namespace std;

int arr[25][25];

int horz(int x,int y)
{
    if(y-3<0)
        return -1;

    return arr[x][y]*arr[x][y-1]*arr[x][y-2]*arr[x][y-3];
}

int vert(int x,int y)
{
    if(x-3<0)
        return -1;

    return arr[x][y]*arr[x-1][y]*arr[x-2][y]*arr[x-3][y];
}

int d1(int x,int y)
{
    if(y-3<0 || x-3<0)
        return -1;

    return arr[x][y]*arr[x-1][y-1]*arr[x-2][y-2]*arr[x-3][y-3];
}

int d2(int x,int y)
{
    if(x-3<0 || y+3 >=20)
        return -1;

    return arr[x][y]*arr[x-1][y+1]*arr[x-2][y+2]*arr[x-3][y+3];
}

int main()
{
    int i,j,k;

    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int ans=0;

    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            ans=max(ans,horz(i,j));
            ans=max(ans,vert(i,j));
            ans=max(ans,d1(i,j));
            ans=max(ans,d2(i,j));
        }
    }

    printf("%d\n",ans);

    return 0;
}
