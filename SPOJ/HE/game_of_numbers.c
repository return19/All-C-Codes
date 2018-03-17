#include<stdio.h>

int main()
{
    long long num;
    scanf("%lld",&num);
    if(num%10==0&&num!=0)
    {
        printf("2\n");
    }
    else
    {
        printf("1\n%lld",num%10);
    }
    return 0;
}
