#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long arr[1010000];

set< pair<long long,long long> > st;

int main()
{
    long long i,j,k;
    long long n;
    long long x;

    scanf("%lld%lld%lld",&n,&k,&x);

    long long mn = LLONG_MAX;
    long long idx;
    long long s=0;
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]<0)
            s = 1-s;

        if(mn>arr[i]){
            mn = arr[i];
            idx = i;
        }
    }

    if(!s){
        long long y  =mn/x;
        if(y>=k){
            arr[idx] -= k*x;
            for(i=0;i<n;i++)
                cout<<arr[i]<<" ";
            return 0;
        }

        arr[idx] -= x*(y+1);
        k-=(y+1);
    }

    for(i=0;i<n;i++)
    {
        st.insert(mp(abs(arr[i]),i));
    }

    for(i=0;i<k;i++){
        pair<long long,long long> p = *(st.begin());
        st.erase(p);
        if(arr[p.sd]<0)
        {
            arr[p.sd]-=x;
        } else {
            arr[p.sd]+=x;
        }
        st.insert(mp(abs(arr[p.sd]),p.sd));
    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";


    return 0;
}
