#include<bits/stdc++.h>
using namespace std;

//int n;
//int a[200000];
//string a;

long long m;

long long cal(long long x)
{

    long long ans = 0;
    long long d = 2;
    long long cub = d*d*d;
    while(cub<=x){
        ans+=(x/cub);
        d++;
        cub = d*d*d;
    }

    return ans;
}

int main()
{
    //freopen("input14.txt","r",stdin);
    //freopen("output14.txt","w",stdout);
    cin>>m;

    long long high = 8;
    long long low;

    while(cal(high)<=m){
        low = high;
        high*=2;
    }

    long long ans = -1;

    while(low<=high){
        long long mid = (low+high)/2;

        long long cm = cal(mid);

        if(cm==m){
            ans = mid;
            high = mid-1;
        }
        else if(cm>m){
            high = mid-1;
        }
        else
            low = mid+1;
    }

    cout<<ans<<endl;

    return 0;
}
