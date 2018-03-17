#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k;
    long long n;
    long long sum=0,temp;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;

        scanf("%lld%lld",&n,&k);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&temp);

            sum+=temp;

        }

        if(sum%2==0)
        {
            if(k==1)
            {
                printf("odd\n");
            }
            else
            {
                printf("even\n");
            }
        }
        else
        {

                printf("even\n");

        }
    }

    return 0;
}
