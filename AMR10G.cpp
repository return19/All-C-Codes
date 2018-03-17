#include<bits/stdc++.h>
using namespace std;

long long arr[20010];


int main()
{
    long long test,n,i,j,k;
    long long min1;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&k);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        sort(arr,arr+n);

        ///////
        /*for(j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<endl;*/
        //////

        min1=99999999999999999;

        for(j=0;j<=n-k;j++)
        {
            if(arr[j+k-1]-arr[j]<min1)
                min1=arr[j+k-1]-arr[j];
        }

        printf("%lld\n",min1);
    }
    return 0;
}
