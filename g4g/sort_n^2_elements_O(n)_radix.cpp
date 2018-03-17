#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int count1[110000];
int output[110000];

void sort_it(int arr[],int n,int exp)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        count1[i]=0;
    }

    for(i=0;i<n;i++)
    {
        count1[(arr[i]/exp)%n]++;
    }

    for(i=1;i<n;i++)
    {
        count1[i]+=count1[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[count1[(arr[i]/exp)%n]-1]=arr[i];
        count1[(arr[i]/exp)%n]--;
    }

    for(i=0;i<n;i++)
    {
        arr[i]=output[i];
    }

}


void sort_radix(int arr[],int n)
{
    sort_it(arr,n,1);
    sort_it(arr,n,n);
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

    sort_radix(arr,n);

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
