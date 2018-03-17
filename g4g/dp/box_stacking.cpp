#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int l;
    int b;
    int h;
};

bool cmp(elem a,elem b)
{
    if(a.l*a.b!=b.l*b.b)
    {
        if(a.l==b.l)
        {
            a.b>b.b;
        }

        return a.l>b.l;
    }

    return a.l*a.b>b.l*b.b;
}

elem arr[11000];
int dp[11000];

int n;

int solve_dp()
{
    int i,j,k=-1;
    dp[0]=arr[0].h;

    for(i=1;i<3*n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j].l>arr[i].l&&arr[j].b>arr[i].b)
            {
                dp[i]=max(dp[i],dp[j]+arr[i].h);
            }
        }
        k=max(k,dp[i]);

    }

    return k;
}

int main()
{
    int i,j,k;

    int x,y,z;

    scanf("%d",&n);

    k=-1;

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        arr[++k].h=x;
        arr[k].b=y;
        arr[k].l=z;


        arr[++k].h=y;
        arr[k].b=x;
        arr[k].l=z;


        arr[++k].h=z;
        arr[k].b=x;
        arr[k].l=y;
    }

    sort(arr,arr+k+1,cmp);

    int ans=solve_dp();

    printf("%d\n",ans);

    return 0;
}










