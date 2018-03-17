#include<stdio.h>

int main()
{
    float init_bal;
    int wid;
    scanf("%d",&wid);
    scanf("%f",&init_bal);
    if(wid>init_bal-1)
    {
        printf("%.2f\n",init_bal);
    }
    else if(wid%5!=0)
    {
        printf("%.2f\n",init_bal);
    }
    else
    {
        init_bal=init_bal-wid-.5;
        printf("%.2f\n",init_bal);
    }


    return 0;
}
