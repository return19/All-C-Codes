#include<stdio.h>

void rev(long long *a)
{
    long long sum=0;
    while(*a!=0)
    {
        sum=10*sum+(*a)%10;
        *a=(*a)/10;
    }
    *a=sum;
}

int main()
{
    int test,i;
    long long num1,num2,sum;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&num1,&num2);
        rev(&num1);
        rev(&num2);
        sum=num1+num2;
        rev(&sum);
        printf("%lld\n",sum);
    }
    return 0;
}
