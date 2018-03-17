#include<stdio.h>
int e(int n)
{int p=1;if(n&&!(n&(n-1)))return n;while(p<n)p<<=1;return p/2;}int f(int g)
{if(g==0)return 0;int i=e(g);g=g-i;f(g);printf("%d ",i);return -1;}int main(){int n;scanf("%d",&n);f(n);return 0;}
