#include<cstdlib>
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
int main()
{   srand(time(NULL));
    int i,k,x,test,flag=0;
    long a,a1,b,b1,m,m1,sum,j;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        sum=0; flag=0;
        /*scanf("%ld",&a);
        scanf("%ld",&b);
        scanf("%ld",&m);*/
        a=rand()%100+1;
        b=a+rand()%1000;
        m=rand()%100+100;
        a1=a;
        b1=b;
        m1=m;

        cout<<a<<" "<<b<<" "<<m<<endl;
    while(1)
     {

       if(m>b)
        {
            printf("0\n");
            break;
        }
        for(j=a;j<=b;j++)
        {
            if(j%m==0)
            {
                sum++;
                break;
            }
        }
        if(j==b+1)
        {
            printf("0\n");
            break;
        }

        sum=sum+(b-j)/m;
        printf("%d\n",sum);

       cout<<"\t\t";
       break;
     }
        a=a1;
        b=b1;
        m=m1;
    while(1)
    {

        if(m>b)
        {
            printf("0\n");
            break;
        }
        for(j=a,k=b;j<=k;j++,k--)
        {
            if(j%m==0)
            {
                sum++;
                break;
            }
            if(k%m==0)
            {
                sum++;
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {   if(j==((b+a)/2)+1)
            {
                printf("0\n");
                break;
            }

            sum=sum+(b-j)/m;
            printf("%d\n",sum);
            break;
        }
        else
        {
            sum=sum+(k-a)/m;
            printf("%d\n",sum);
            break;
        }
    }
    }
    return 0;
}
