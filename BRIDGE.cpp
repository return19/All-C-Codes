#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int st;
    int ed;
};

elem arr[1010];

int cmp(elem a,elem b)
{
    if(a.st==b.st)
        return a.ed<b.ed;

    return a.st<b.st;
}

int rm[1010];

int main()
{
    int test,i,j,k;
    int t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].st);
            rm[i]=1;
        }

         for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].ed);
        }

        sort(arr,arr+n,cmp);

        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(arr[j].ed<=arr[i].ed&&rm[j]+1>rm[i])
                 rm[i]=rm[j] + 1;

            }
        }

        int ans=INT_MIN;

        for(i=0;i<n;i++)
            ans=max(ans,rm[i]);

        if(ans!=INT_MAX)
            printf("%d\n",ans);
        else
            printf("0\n");

    }

    return 0;
}









