#include<stdio.h>
int main()
{
    int t,i;
    long n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%ld",&n);
        n=(3*n+n*n)/2;
        printf("%ld\n",n);
    }
    return 0;
}
