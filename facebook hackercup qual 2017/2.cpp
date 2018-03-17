#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
   // freopen("in1.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    long long i,j,k;
    long long n;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n);

        long long ans=0;
        long long st=0;

        for(i=n-1;i>=st;i--){
            long long cur=arr[i];
            while(cur<50 && i>st){
                cur += arr[i];
                st++;
            }

            if(cur>=50)
                ans++;
        }

        printf("Case #%lld: %lld\n",t+1,ans);
    }
    return 0;
}















