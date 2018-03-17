#include<bits/stdc++.h>
using namespace std;

unsigned long long n;

unsigned long long one[1100];
unsigned long long zero[1100];

void solve()
{
    unsigned long long i,j,k;

    one[1]=1;
    zero[1]=1;

    for(i=2;i<=100;i++)
    {
        one[i]=zero[i-1];
        zero[i]=zero[i-1]+one[i-1];
    }
}

int main()
{
    unsigned long long i,j,k;

    solve();

    scanf("%llu",&n);

    printf("%llu\n",one[n]+zero[n]);

    return 0;
}
