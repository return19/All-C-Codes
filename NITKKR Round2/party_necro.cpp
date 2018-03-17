#include<bits/stdc++.h>
using namespace std;

double a[2001000];
int n,k;
int main()
{
    int x;
    cin>>n>>k;

    double mx = DBL_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //a[i] = M_PI*x*x;
        mx = max(mx,a[i]);
    }

    double low = 0;
    double high = mx;
    double mid;
    while((high-low)>1e-6){
        mid = (low+high)/2;
        int c=0;

        for(int i=0;i<n;i++)
            c+=((int)(a[i]/mid));

        if(c<k)
            high = mid;
        else
            low = mid;
    }

    printf("%.4lf\n",mid);

    return 0;
}
