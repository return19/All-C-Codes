#include<stdio.h>

int main()
{
    float l,area,pi=3.1415926f;
    long temp;
    scanf("%f",&l);

    while(l!=0)
    {
        area=(l*l)/(2*pi);
        area=area*1000;
        temp=(long)area;
        if(temp%10>=5)
        {
            temp=temp/10;
            temp++;
        }
        else
        {
            temp=temp/10;
        }
        area=(float)temp/100;
        printf("%.2f\n",area);

        scanf("%f",&l);
    }
    return 0;
}
