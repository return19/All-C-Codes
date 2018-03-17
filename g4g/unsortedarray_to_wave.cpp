#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int main()
{
    int i,j;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;)
    {
        if(arr[i]<arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }

        i++;

        if(i==n-1)
            break;

        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        i++;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}





