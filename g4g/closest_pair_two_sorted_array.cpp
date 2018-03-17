#include<bits/stdc++.h>
using namespace std;

int arr1[110000];
int arr2[110000];

int main()
{
    int i,j,k;
    int n1,n2;

    scanf("%d",&n1);

    for(i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);
    }

    scanf("%d",&n2);

    for(i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);
    }

    i=0;    j=n2-1;
    int x;

    scanf("%d",&x);

    int ans=abs(arr1[i]+arr2[j]-x);
    int sum=arr1[i]+arr2[j],l=0,r=n2-1;

    while(i<n1&&j>=0)
    {

            sum=arr1[i]+arr2[j];

             if(sum==x)
            {
                l=i;
                r=j;
                break;
            }

            if(abs(sum-x)<ans)
            {
                ans=abs(sum-x);
                l=i;
                r=j;
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

    printf("%d %d",arr1[l],arr2[r]);

    return 0;
}
