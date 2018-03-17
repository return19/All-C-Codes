#include<stdio.h>

int main()
{
    long long int n,d2,d3,d4,sum[100];
    int test,i;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {

        scanf("%lld",&n);
        d2=n/2;
        d3=n/3;
        d4=n/4;
        sum[i]=d2+d3+d4;
        if(sum[i]<n)
        {
            sum[i]=n;
        }
    }
    for(i=0;i<test;i++)
        printf("%lld\n",sum[i]);
    return 0;


}

