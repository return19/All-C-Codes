#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main(){
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    long long ans=0;
    long long sum=0;
    long long res=0;
    for(i=0;i<n;i++){
        if(sum!=0)
            res++;
        sum += arr[i];
    }

    ans=res;

    long long st=0,ed=n-1;

    while(st<n && arr[st]==0)
        st++;

    while(ed>=0 && arr[ed]==0)
        ed--;

    if(st>=ed)
        ans=0;
    else{
        res=0;
        sum=arr[st];
        i=(st-1+n)%n;
        for(;i!=st;i=(i-1+n)%n){
            if(sum!=0)
                res++;
            sum += arr[i];
        }
        ans=min(ans,res);
    }

    printf("%lld\n",ans);

    return 0;
}

