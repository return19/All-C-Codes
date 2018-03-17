#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k;
    long long n;
    long long temp;
    long long t,flag=0;

    test=1;

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        flag=0;

        if(n>0)
        {
            t=n+1;

            while(t)
            {
                if(t%10==8)
                {
                    flag=1;
                    break;
                }
                  t=t/10;

            }

            if(flag==1)
            {
                printf("1\n");
                return 0;
            }

            if(n%100==79)
            {
                printf("1\n");
                return 0;
            }

            if(n%10==9)
            {
                printf("9\n");
                return 0;
            }

            if(n%10==8)
            {
                printf("10\n");
                return 0;
            }

            printf("%lld\n",8-n%10);

            return 0;
        }
        else if(n<0)
        {
            n=n*(-1);

            t=n-1;

            while(t)
            {
                if(t%10==8)
                {
                    flag=1;
                    break;

                }
                t=t/10;
            }

            if(flag==1)
            {
                printf("1\n");
                return 0;
            }

            if(n/10==0)
            {
                if(n==9)
                {
                    printf("1\n");
                    return 0;
                }

                printf("%lld\n",8+n);
                return 0;
            }

            if(n%10==9)
            {
                printf("1\n");
                return 0;
            }

            if(n%10==8)
            {
                printf("10\n");
                return 0;
            }

            printf("%lld\n",n%10+2);
            return 0;
        }


        if(n==0)
        {
            printf("8\n");
        }
    }

    return 0;
}
