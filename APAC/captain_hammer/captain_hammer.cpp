#include<bits/stdc++.h>
using namespace std;

double g=9.8;

double pi=3.14159265359;

int main()
{
    int test,i,j,k;

    int t;

    int v,d;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&v,&d);

        double in= (d*g)/(v*v);

        double ans= (asin(in)*180)/pi;
        ans=ans/2;

        printf("Case #%d: %.8lf\n",t+1,ans);
    }

    return 0;
}
