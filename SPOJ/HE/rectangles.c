#include<stdio.h>

int main()
{
    long n,sum=0,rect,i=2;
    scanf("%d",&n);
    rect=n/i-(i-1);
    sum=n;
    while(rect>0)
    {
        sum=sum+rect;
        i++;
        rect=(n/i)-(i-1);
    }
    printf("%ld",sum);
    return 0;
}
