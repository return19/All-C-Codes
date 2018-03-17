#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int st;
    int ed;
};

int cmp(elem a,elem b)
{
    if(a.ed==b.ed)
        return a.st<b.st;
    return a.ed<b.ed;
}

elem arr[101000];

int main()
{
    int test,t,i,j,k;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&arr[i].st,&arr[i].ed);
        }

        sort(arr,arr+n,cmp);

        int prev=arr[0].ed;
        int ans=1;

        for(i=1;i<n;i++)
        {
            if(arr[i].st>=prev)
            {
                ans++;
                prev=arr[i].ed;
            }
        }

        printf("%d\n",ans);

    }

    return 0;
}
