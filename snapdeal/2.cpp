#include<bits/stdc++.h>
using namespace std;

long long a[250000];

int main()
{
    long long n,q;

    cin>>n>>q;

    for(long long i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    long long x,k,t;
    while(q--){

        cin>>x>>k>>t;

        long long p = lower_bound(a,a+n,x) - a;

        cout<<p<<endl;


        if(t==0){

            if(p>=n)
            {
                cout<<-1<<endl;
                continue;
            }
            long long z;
            if(a[p]>x)
                z = p+k-1;
            else
                z= p+k;

            if(z>=n)
                cout<<-1<<endl;
            else
                cout<<a[z]<<endl;

        }
        else{

            long long z = p-k;

            if(z<0)
                cout<<-1<<endl;
            else
                cout<<a[z]<<endl;
        }

    }

    return 0;
}
