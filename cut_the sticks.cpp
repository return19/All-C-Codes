#include<bits/stdc++.h>
using namespace std;

int arr[1100];

int main()
{
    int n;
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+n);

    for(i=0;i<n;)
    {
        printf("%d",n-i);

        int cur=arr[i];

        while(arr[i]==cur)
            i++;
    }


    return 0;
}
