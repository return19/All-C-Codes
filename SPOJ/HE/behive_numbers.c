#include<stdio.h>

int main()
{
    long long n,i,sum=0;
    int flag=0;

    scanf("%lld",&n);

    while(n!=-1)
    {

        n=n-1;
        sum=0;  flag=0;
        for(i=0;sum<=n;i++)
        {
            sum=sum+6*i;
            if(sum==n)
            {
                printf("Y\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("N\n");
        }


        scanf("%lld",&n);
    }
    return 0;
}
