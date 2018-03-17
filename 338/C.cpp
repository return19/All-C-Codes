#include<bits/stdc++.h>
using namespace std;

map<unsigned long long,unsigned long long> arr;
map<unsigned long long,unsigned long long>::iterator it,pr,nx,tmp;
map<unsigned long long,unsigned long long>::reverse_iterator rit;
unsigned long long inp[201000];
unsigned long long powers[201000];

unsigned long long M=1000000007,N=1000000006;

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long m)
{
    if (y == 0)
        return 1;
    unsigned long long p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}



unsigned long long inverseNumber(unsigned long long num) {

            unsigned long long MOD=N;
            // Inverse modulo : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
            // Calculate num ^ MOD-2  % MOD
            unsigned long long ans = 1, base = (unsigned long long) num;
            unsigned long long power = MOD - 2;
            while (power > 0) {
                if (power == 1) {
                    return (ans * base) % MOD;
                }
                if (power % 2 == 0) {
                    base = (base * base) % MOD;
                    power /= 2;
                } else {
                    ans = (ans * base) % MOD;
                    power--;
                }
            }
            return ans;
        }


// To compute x^y under modulo m

unsigned long long l[201000];
unsigned long long r[201000];
unsigned long long sum[201000];

int main()
{
    unsigned long long i,j,k;
    unsigned long long n;
    unsigned long long pro=1;
    unsigned long long ans=1;

    for(i=1;i<=200110;i++)
        sum[i]=(sum[i-1]+i)%N;

    scanf("%llu",&n);

    for(i=0;i<n;i++)
    {
        scanf("%llu",&inp[i]);
        arr[inp[i]]++;
    }

    unsigned long long prev=1;

    for(it=arr.begin();it!=arr.end();it++)
    {
        l[it->first]=(prev*(it->second+1))%N;
        prev=l[it->first];
    }

    prev=1;

    for(rit=arr.rbegin();rit!=arr.rend();rit++)
    {
        r[rit->first]=(prev*(rit->second +1))%N;
        prev=r[rit->first];
    }

    for(it=arr.begin();it!=arr.end();it++)
    {
        tmp=it;
        it++;
        nx=it;
        it=tmp;
        unsigned long long num=it->second;

        unsigned long long temp=sum[num];

        if(it!=arr.begin())
            temp=(temp*(l[pr->first]))%N;
        if(nx!=arr.end())
            temp=(temp*(r[nx->first]))%N;

        ans=(ans*power(it->first,temp,M))%M;
        pr=it;
    }

    printf("%llu\n",ans%M);

    return 0;
}
