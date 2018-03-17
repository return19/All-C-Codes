#include<bits/stdc++.h>
using namespace std;

int arr[10100];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n);

   /* for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
        i++;
        if(i==n-1)
            break;
       if(arr[i]<arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

