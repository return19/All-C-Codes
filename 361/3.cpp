#include<bits/stdc++.h>
using namespace std;

long long solve(long long x){
    long long i=2;
    long long temp=0;
    while(x/(i*i*i)>=1){
        temp += (x/(i*i*i));
        i++;
    }
    return temp;
}

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    long long l=8,r=1e16;

    while(l<=r){
        long long mid = l + (r-l)/2;

        long long temp=solve(mid);
        long long temp1=solve(mid-1);
        //cout<<mid<<" "<<temp<<endl;

        if(temp==n && temp1<n){
            printf("%lld\n",mid);
            return 0;
        }
        if(temp<n)
            l=mid+1;
        else if(temp>=n)
            r=mid-1;
    }
    printf("-1\n");

    return 0;
}

