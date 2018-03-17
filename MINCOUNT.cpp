#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long test,i,j,k;
    unsigned long long n,temp;


    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu",&n);

        if(n%2==0)
        {
            temp=n/2;
            temp=temp*(n+1)/3;
        }
        else
        {
            temp=(n+1)/2;
            temp=temp*n/3;
        }

        printf("%llu\n",temp);
    }

    return 0;
}
