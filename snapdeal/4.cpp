#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int st;
    int ed;
};

elem arr[101000];

int inside(int x,int y,int a,int b)
{
    if(x>=a&&y<=b)
        return 1;
    return 0;
}

int main()
{
    int n,i,j,k;
    int q;

    scanf("%d",&n);

    scanf("%d",&q);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&arr[i].st,&arr[i].ed);
    }

    int x,y,a,b;

    for(i=0;i<q;i++)
    {
        scanf("%d%d%d%d",&a,&b,&x,&y);

        int ans=0;

        for(j=x;j<=y;j++)
        {
            if(inside(arr[j].st,arr[j].ed,a,b))
                ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}
