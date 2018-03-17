#include<stdio.h>

int main()
{
 long long test,n,sum=0,i,j,candy;
 scanf("%lld",&test);
 for(i=0;i<test;i++)
 {
     sum=0;
     printf("\n");
     scanf("%lld",&n);

     for(j=0;j<n;j++)
     {
         scanf("%lld",&candy);
         sum=(sum+candy)%n;
     }
     if(sum==0)
     {
          printf("YES\n");
     }
     else
     {
          printf("NO\n");
     }
 }
 return 0;
}
