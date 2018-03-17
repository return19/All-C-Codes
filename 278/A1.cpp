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
        if(n>0){
            for(j=1;j<=10;j++)
            {
                temp=j+n;

                while(temp!=0)
                {
                    t=temp%10;
                    if(t==8)
                    {
                        flag=1;
                        break;
                    }
                    temp=temp/10;
                }

                if(flag==1)
                    break;

            }

            printf("%lld\n",j);
        }
        else if(n<0)
        {
            n=n*(-1);

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


            for(j=1;j<=10;j++)
            {

                temp=n-j;

                while(temp!=0)
                {
                    t=temp%10;
                    if(t==8)
                    {
                        flag=1;
                        break;
                    }
                    temp=temp/10;
                }

                if(flag==1)
                    break;

            }

            printf("%lld\n",j);
        }
        else
        {
            printf("8\n");
        }
    }

    return 0;
}
