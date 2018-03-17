#include<bits/stdc++.h>
using namespace std;

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

    i=0;
    j=n-1;

    int sum,ans=INT_MAX;
    int x,l,r;

    scanf("%d",&x);

    while(i<n&&j>=0)
    {
        sum=arr[i]+arr[j];

        if(sum==x)
        {
            l=i;
            r=j;
            ans=0;
            break;
        }

        if(ans>abs(sum-x))
        {
            l=i;
            r=j;
            ans=abs(sum-x);
        }

        if(sum>x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    printf("%d %d\n",arr[l],arr[r]);

    return 0;
}










