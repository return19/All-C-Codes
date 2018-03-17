#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

bool is_perfect_cube(unsigned long long n) {
    unsigned long long root(round(cbrt(n)));
    return n == root * root * root;
}

int main()
{
    unsigned long long test,i,j,k,n;

    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu",&n);

        scanf("%llu",&n);

        for(j=2;;j++)
        {
            if(is_perfect_cube(n*j))
            {
                printf("%llu\n",(n*j)%M);
                break;
            }
        }
    }

    return 0;
}
