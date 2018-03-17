#include<stdio.h>

int main()
{
    int i,test;
    long a,b,m,sum,j;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%ld",&a);
        scanf("%ld",&b);
        scanf("%ld",&m);

        if(m>b)
        {
            printf("0\n");
            continue;
        }
        for(j=a;j<=b;j++)
        {
            if(j%m==0)
            {
                sum++;
                break;
            }
        }
        if(j==b+1)
        {
            printf("0\n");
            continue;
        }

        sum=sum+(b-j)/m;
        printf("%d\n",sum);
    }
    return 0;
}
