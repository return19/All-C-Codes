#include<stdio.h>
int main()
{
    long long test,i,sum=0,lvl,x,tri;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%lld",&lvl);
        sum=lvl*lvl+(lvl*(lvl-1)*(lvl+1))/6;
        if(lvl%2==0)
            {x=(lvl-4)/2;}
        else
            {x=(lvl-5)/2;}
        tri=((lvl-3)*(lvl-2)+lvl*lvl*x-5*lvl*x-2*lvl*x*(x+1)+6*x+5*x*(x+1)+(2*x*(x+1)*(2*x+1))/3);
        printf("%lld\n",sum+tri/2);
    }
    return 0;
}
