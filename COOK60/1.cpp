#include<bits/stdc++.h>
using namespace std;

long long arr[110000];

int main()
{
    long long test,i,j,k;
    long long n,d;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&d);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        sort(arr,arr+n);

        /*for(j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<endl;*/

        long long ans=0;

        for(j=n-1;j>0;j--)
        {
            if(arr[j]-arr[j-1]<d)
            {
                ans=ans+arr[j]+arr[j-1];
                j--;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
