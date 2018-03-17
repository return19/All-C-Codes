#include<bits/stdc++.h>
using namespace std;

long long arr[100110];

long long n,cow;

long long check(long long num)
{
    long long c=1,i,j,pos=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]-pos>=num){
            c++;
            pos=arr[i];
        }
        if(c==cow)
            return 1;

    }
    return 0;

}

long long init()
{
    long long i,j,k,mid,start=0,last=arr[n-1];
    long long max1=-99999;

    while(start<=last)
    {
        mid=(start+last)/2;

        if(check(mid))
        {
            if(max1<mid)
            {
                max1=mid;
            }

            start=mid+1;
        }
        else
        {
            last=mid-1;
        }

    }

    return max1;
}

int main()
{
    long long test,i,j,k,ans;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&cow);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        sort(arr,arr+n);
        ans=init();

        printf("%lld\n",ans);
    }
    return 0;
}
