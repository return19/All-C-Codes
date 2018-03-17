#include<stdio.h>
#include<math.h>

int main()
{
    long long num1,num2,p,j,k;
    int test,i,flag=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&num1,&num2);

        for(j=num1;j<=num2;j++)
        {
            flag=0;
            if(j==1)
                continue;
            for(k=2;k<=sqrt(j);k++)
            {
                if(j%k==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {

                printf("%lld\n",j);
            }
        }
        printf("\n");
    }
}
