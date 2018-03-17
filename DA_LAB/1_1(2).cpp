#include<bits/stdc++.h>
using namespace std;

int part(int arr[],int low,int high)
{
    int pivot=low;
    int i=low,j=high;

    while(i<j)
    {
        while(i<high&&arr[i]>=arr[pivot])
            i++;

        while(arr[j]<arr[pivot])
            j--;

        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;

    return j;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int i=part(arr,low,high);

        quicksort(arr,low,i-1);
        quicksort(arr,i+1,high);
    }
}

int arr[11000];

int main()
{
    int i,j,k;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    quicksort(arr,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}










