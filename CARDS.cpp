#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,num,sum,i,j;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&num);
        sum=((num+num*num*3)/2)%1000007;
        printf("%lld\n",sum);
    }

    return 0;
}
















