#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int main()
{
    int i,j,k;
    int n;
    int ans;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int st,ed;

    for(i=0;i<n;i++)
    {
        if(i==n-1)
            st=-1;

        if(arr[i]>arr[i+1])
        {
            st=i;
            break;
        }
    }

    if(st==-1)
    {
        ans=0;
        printf("%d\n",ans);
        return 0;
    }

    for(i=n-1;i>0;i--)
    {
        if(arr[i]<arr[i-1])
        {
            ed=i;
            break;
        }
    }

    int max_val=INT_MIN;
    int min_val=INT_MAX;

    for(i=st;i<=ed;i++)
    {
        max_val=max(max_val,arr[i]);
        min_val=min(min_val,arr[i]);
    }

    for(i=0;i<st;i++)
    {
        if(arr[i]>min_val)
        {
            st=i;
            break;
        }
    }

    for(i=n-1;i>ed;i--)
    {
        if(arr[i]<max_val)
        {
            ed=i;
            break;
        }
    }

    printf("%d %d\n",st,ed);



    return 0;
}
