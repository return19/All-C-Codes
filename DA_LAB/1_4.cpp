#include<bits/stdc++.h>
using namespace std;

int arr[11000];
//max_heap
void percolate_down(int arr[],int n,int idx)
{
    if(idx==n)
        return;

    int l,r;

    l=idx*2+1;
    r=idx*2+2;

    int max_val=arr[idx];
    int max_idx=idx;

    if(l<n&&arr[l]>max_val)
    {
        max_idx=l;
        max_val=arr[l];
    }

    if(r<n&&arr[r]>max_val)
    {
        max_idx=r;
        max_val=arr[r];
    }

    if(max_idx!=idx)
    {
        int temp=arr[idx];
        arr[idx]=arr[max_idx];
        arr[max_idx]=temp;

        percolate_down(arr,n,max_idx);
    }
}

void delete_index(int arr[],int &n,int idx)
{
    arr[idx]=arr[n-1];

    n--;

    percolate_down(arr,n,idx);
}

void heapify(int arr[],int n)
{
    int i,j;

    for(i=n/2-1;i>=0;i--)
    {
        percolate_down(arr,n,i);
    }
}

int extract_max(int arr[],int &n)
{
    int ans=arr[0];
    arr[0]=arr[n-1];
    n--;

    percolate_down(arr,n-1,0);

    return ans;
}

int main()
{
    int i,j,k;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    heapify(arr,n);

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    cout<<"Enter index k : ";
    scanf("%d",&k);

    delete_index(arr,n,k);

     for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

