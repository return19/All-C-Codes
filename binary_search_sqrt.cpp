#include<bits/stdc++.h>
using namespace std;

double nthroot(double x,int n)
{
    int i,j,k;
    double mid;
    double st=1,ed=x;

    while(st<=ed){
        mid=(st+ed)/2;
        if(x>=pow(mid,n) && x-pow(mid,n) < 0.0001)
            return mid;
        if(x>pow(mid,n))
            st=mid;
        else
            ed=mid;
    }
    return -1;
}

int main()
{
    int i,j,k;
    int n=8;
    cout<<setprecision(5)<<nthroot(10,n)<<endl;
    cout<<pow(10,1.0/n);

    return 0;
}
