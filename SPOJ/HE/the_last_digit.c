#include<stdio.h>
#include<string.h>
int main()
{
    unsigned long long test,i,n,arr[210],index,temp,a,b;
    char d[2010];
    scanf("%llu",&test);
    for(i=0;i<test;i++)
    {
        scanf("%s",d);
        scanf("%llu",&b);
        n=strlen(d);
        a=d[n-1]-48;
        if(a==0&&b==0)
        {printf("0\n");continue;}
        else if(b==0)
        {printf("1\n");continue;}
        temp=(a*a)%10;index=0;
        arr[index++]=a;
        while(temp!=a)
        {arr[index++]=temp;temp=(a*temp)%10;}
        if(b%(index)!=0)
        {b=b%(index)-1;}
        else
        {b=index-1;}
        printf("%llu\n",arr[b]);
    }
    return 0;
}
