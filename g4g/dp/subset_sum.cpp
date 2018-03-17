#include<bits/stdc++.h>
using namespace std;

int arr[1100];

int temp[1100];

int subset_sum(int arr[],int n,int sum)
{
    int i,j,k;
    int start=0;

    temp[0]=1;

    for(i=0;i<n;i++)
    {
        for(j=start+arr[i];j>=arr[i];j--)
        {
            if(temp[j-arr[i]])
                temp[j]=1;
        }

        start+=arr[i];
    }

    return temp[sum];
}

int main()
{
    int i,j,k;

    int n,sum;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&sum);

    int check=subset_sum(arr,n,sum);

    if(check)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
