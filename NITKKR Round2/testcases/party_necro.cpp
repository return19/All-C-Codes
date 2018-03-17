#include<bits/stdc++.h>
using namespace std;

long double a[2001000];
long long n,k;
int main()
{
    //freopen("input10.txt","r",stdin);
    f//reopen("output10.txt","w",stdout);
    long long x;
    cin>>n>>k;

    long double mx = DBL_MIN;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        //a[i] = M_PI*x*x;
        mx = max(mx,a[i]);
    }

    long double low = 0;
    long double high = mx;
    long double mid;
    while((high-low)>1e-4){
        mid = (low+high)/2;
       // cout<<high-low<<endl;
        long long c=0;

        for(long long i=0;i<n;i++)
            c+=((long long)(a[i]/mid));

        if(c<k)
            high = mid;
        else
            low = mid;
    }

    //printf("%.4lf\n",mid);
    cout<<setprecision(22)<<mid<<endl;

    return 0;
}
