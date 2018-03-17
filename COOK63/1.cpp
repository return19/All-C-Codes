#include<bits/stdc++.h>
using namespace std;

int arr[1010000];

int main()
{
    int test,t,i,j,k;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
                swap(arr[i],arr[i+1]);
        }

        int ans=0;

        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                ans=1;
                break;
            }
        }

        if(ans==0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}








