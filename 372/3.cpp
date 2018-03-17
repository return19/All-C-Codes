#include<bits/stdc++.h>
using namespace std;

int arr[101000];

long long solve(long long &cur, long long l){
    long long i,j,k;

    for(i=l+1;;i+=(l+1)){
        if((i*i -cur)%l ==0){
            long long ans = (i*i-cur)/l;
            cur = i;
            return ans;
        }
    }
}

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    long long x = 2;
    long long l = 1;

    for(i=1;i<=n;i++){
        arr[i] = solve(x,l);
        cout<<arr[i]<<" ";
        l++;
    }

    return 0;
}
