#include<bits/stdc++.h>
using namespace std;

long long pow(long long a, long long b, long long MOD) {
long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long modInverse(long long a, long long m) {
    return pow(a,m-2,m);
}

int main()
{
    cout<<modInverse(2,1000000007);
    return 0;
}
