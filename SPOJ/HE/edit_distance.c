#include<stdio.h>
#include<string.h>
char a[4000],b[4000];
int main()
{

    long long test,i,j,sum=0,n1,n2,d;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%s",a);
        scanf("%s",b);
        n1=strlen(a);
        n2=strlen(b);
        if(n2>n1)
        {
            d=n2-n1;
        }
        else
        {
            d=n1-n2;
        }
        sum=d;
        for(j=0;a[j]!='\0'&&b[j]!='\0';j++)
        {
            if(a[j]!=b[j])
            {
                sum++;
            }
        }
        printf("%lld\n",sum);

    }
    return 0;
}
