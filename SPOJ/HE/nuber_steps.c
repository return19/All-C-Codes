#include<stdio.h>

int main()
{
    long long test,x,y,i,j;


    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&x,&y);
        if((x==1&&y==1)||(x==0&&y==0))
        {
            printf("%lld\n",x);
            continue;
        }

        if(x-y==2)
        {
            if(x%2==0)
            {
                printf("%lld\n",2*(x-1));
            }
            else
            {
                printf("%lld\n",2*(x-1)-1);
            }
        }
        else if(x==y)
        {
            if(x%2==0)
            {
                printf("%lld\n",2*x);
            }
            else
            {
                printf("%lld\n",2*x-1);
            }
        }
        else
        {
            printf("No Number\n");
        }
    }
    return 0;
}
