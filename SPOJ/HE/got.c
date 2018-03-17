#include<stdio.h>
#include<math.h>
int main()
{
int x,n;
float n1;
scanf("%d",&x);
n=(-1+(float)sqrt(1+8*x))/2;
if(n*(n+1)/2==x)
printf("%d",n);
else
    printf("%d",n+1);
return 0;
}
