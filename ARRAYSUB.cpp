#include<bits/stdc++.h>
using namespace std;

int arr[1000010];

int l[1000010];
int r[1000010];

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    int n,i,j,k,max1=0,m;


    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&k);

    //max2=arr[0];

    for(i=0;i<n;i++)
    {
        if((i+1)%k==0)
        {
            max1=0;
        }
        if(max1<arr[i])
            max1=arr[i];

        l[i]=max1;
    }

    for(i=n-1;i>=0;i--)
    {
        if((i+1)%k==0)
            max1=0;

        if(max1<arr[i])
            max1=arr[i];

        r[i]=max1;
    }

    for(i=0;i<n-k+1;i++)
    {
        printf("%d ",max2(r[i],l[i+k-1]));
    }

    printf("\n");

    return 0;
}
