#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n;
    long long a,b;
    long long test;
    long long s;


    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&a,&b);

        while(a>=0&&b>=0&&(a!=b))
        {
            if(a>b)
            {
                a=a-b;
            }
            else
            {
                b=b-a;
            }
        }

        printf("%lld\n",a);
    }


    return 0;
}

