#include<bits/stdc++.h>
using namespace std;

long long a[5];
long long ans[5];

vector<long long> v;

int main()
{
    long long i,j,k;
    long long n;
    long long x;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        v.push_back(x);
    }

    for(i=0;i<5;i++)
        scanf("%lld",&a[i]);

    long long sum=0;
    for(i=0;i<n;i++){
        sum  += v[i];

        while(sum >= a[0]){
            j=0;
            while( j+1 < 5 && a[j+1] <= sum)
                j++;
            ans[j] = ans[j] + sum/a[j];
            sum %= a[j];
        }
    }

    for(i=0;i<5;i++)
        cout<<ans[i]<<" ";
    cout<<endl<<sum<<endl;

    return 0;
}
