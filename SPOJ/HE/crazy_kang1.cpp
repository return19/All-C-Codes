#include<stdio.h>

int main()
{
    int i,k,test,flag=0;
    long a,b,m,sum,j;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        sum=0; flag=0;
        scanf("%ld",&a);
        scanf("%ld",&b);
        scanf("%ld",&m);

        if(m>b)
        {
            printf("0\n");
            continue;
        }
        for(j=a,k=b;j<=k;j++,k--)
        {
            if(j%m==0)
            {
                sum++;
                break;
            }
            if(k%m==0)
            {
                sum++;
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {   if(j==(b+a)/2+1)
            {
                printf("0\n");
                continue;
            }

            sum=sum+(b-j)/m;
            printf("%d\n",sum);
        }
        else
        {
            sum=sum+(k-a)/m;
            printf("%d\n",sum);
        }
    }
    return 0;
}
