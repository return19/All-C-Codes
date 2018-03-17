#include<stdio.h>

int main()
{
    int i,test,num,pow=5,count=0;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        pow=5;
        count=0;
        scanf("%d",&num);
        while(num/pow!=0)
        {
        count+=num/pow;
        pow*=5;
        }
        printf("%d\n",count);
    }
    return 0;
}
