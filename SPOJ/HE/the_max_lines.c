#include<stdio.h>

int main()
{
    int test,i,r;
    double s;

    scanf("%d",&test);

    for(i=1;i<=test;i++)
    {
        scanf("%f",&r);
        s=4*r*r+0.25f;
        printf("Case %d: %.2f\n",i,s);
    }
    return 0;
}
