#include<stdio.h>

int main()
{
    long long test,i,p1,p2,k,x;
    double ratio;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&x,&k);
        p1=2,p2=1;
        while(p1<=k)
        {
            p1=p1*2;
        }
        p2=p1/2;
        ratio=(2*(k-p2)+1);
        ratio=(ratio/p1)*x;
        printf("%lf\n",ratio);

    }
    return 0;

}
