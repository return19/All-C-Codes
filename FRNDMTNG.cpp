#include<bits/stdc++.h>
using namespace std;

double T1,T2,t1,t2;

void swap_it()
{
    double temp;

    temp=T1;
    T1=T2;
    T2=temp;

    temp=t1;
    t1=t2;
    t2=temp;
}

int main()
{
    long long test,i,j,k;
    double x;
    double ans,a1,a2;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lf%lf%lf%lf",&T1,&T2,&t2,&t1);

        if(t1==0&&t2==0)
        {
            printf("0\n");
            continue;
        }

        if(T1>T2)
            swap_it();

        t1=t1/T2;
        t2=t2/T2;

        a1=T1/T2;
        a1=a1-t1;
        a1=(a1*a1)/2;

        a2=1-t2;
        a2=(a2*a2)/2;

        x=1-t2-T1/T2;

        if((1-t2)>T1/T2)
            a2=a2-(x*x)/2;

        if(t1>=T1/T2)
            a1=0;
        if(t2>=1)
            a2=0;

        ans=(T1/T2-a1-a2)/(T1/T2);

        printf("%.9lf\n",ans);
    }
    return 0;
}
