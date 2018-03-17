#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int bsearch(int arr[],int low,int high)
{
    if(low>high)
        return -1;

    int mid=low+(high-low)/2;

    if(arr[mid]==0&&mid!=0&&arr[mid-1]==1)
        return mid-1;
    else if(arr[mid]==0&&mid==0&&arr[mid-1]==1)
    {
        return -1;
    }
    if(arr[mid]==1&&(arr[mid+1]==0||mid==high))
        return mid;

    if(arr[mid]==1)
        return bsearch(arr,mid+1,high);
    else
        return bsearch(arr,low,mid-1);
}

int main()
{
    int i,j,k;

    int n;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int ans=bsearch(arr,0,n-1);

    if(ans==-1)
        cout<<0<<endl;
    else
        cout<<ans+1<<endl;

    return 0;
}

