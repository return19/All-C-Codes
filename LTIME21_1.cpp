#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,count1=0,i,j,k,temp,n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        scanf("%lld",&n);


        while(n!=0)
        {
            temp=n%10;
            if(temp==4)
                count1++;
            n=n/10;
        }

        printf("%lld\n",count1);
    }

    return 0;
}
