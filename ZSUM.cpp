#include<bits/stdc++.h>
using namespace std;

unsigned long long M=10000007;

unsigned long long power(unsigned long long n,unsigned long long k)
{
    if(k==0)
        return 1;

    unsigned long long i,pow,ans;

    pow=power(n,k/2)%M;

    if(k&1)
    {
        ans=(((pow*pow)%M)*n)%M;
    }
    else
    {
        ans=(pow*pow)%M;
    }

    return ans%M;
}

int main()
{
    unsigned long long test,i,j;
    unsigned long long n,k,ans;

    scanf("%llu%llu",&n,&k);

    while(n!=0&&k!=0)
    {
       // cout<<power(n,k)<<" "<<power(n-1,k)*2<<endl;
        ans=(power(n,k)+(2*(power(n-1,k)))%M+(power(n,n)+2*power(n-1,n-1))%M)%M;

        printf("%llu\n",ans);

        scanf("%llu%llu",&n,&k);
    }

    return 0;
}
