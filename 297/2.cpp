#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

vector<long long> v;

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    sort(arr,arr+n,greater<long long>());

    for(i=0;i<n;)
    {
        if(i<n-1 && abs(arr[i]-arr[i+1])<=1 ){
            v.push_back(min(arr[i],arr[i+1]));
            i+=2;
        }else
            i++;
    }
    long long ans=0;
    for(i=0;i<v.size();)
    {
        if(i+1<v.size()){
            ans += (v[i]*v[i+1]);
            i+=2;
        }
        else
            i++;
    }

    printf("%lld\n",ans);

    return 0;
}

