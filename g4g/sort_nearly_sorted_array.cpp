#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(nk)
*/




int arr[110000];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=1;i<n;i++)
    {
        j=arr[i];

        k=i-1;

        while(arr[k]>j&&k>=0)
        {
            arr[k+1]=arr[k];
            k--;
        }
        arr[k+1]=j;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
