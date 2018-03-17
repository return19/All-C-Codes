#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;
    double a,b,c,d;
    double arr[5];
    int n;

    double mn,md;
    double df;

    scanf("%d",&n);

    if(n==0)
    {
        printf("YES\n");
        printf("1\n1\n3\n3\n");
    }
    else if(n==1)
    {
        scanf("%lf",&a);
        printf("YES\n");
        printf("%.0lf\n%.0lf\n%.0lf\n",2*a,2*a,3*a);
    }
    else if(n==2)
    {
        scanf("%lf%lf",&arr[0],&arr[1]);

        sort(arr,arr+2);

        a=arr[0];
        b=arr[1];

        d=3*a;
        c=4*a-b;

        if(c<=0)
        {
            printf("NO\n");
            return 0;
        }

        df=d-a;
        md=(c+b)/2;
        mn=(a+b+c+d)/4;

         if(df==md&&md==mn)
        {
            printf("YES\n");
            printf("%.0lf\n%.0lf\n",c,d);
        }
        else
        {
            printf("NO\n");
        }


    }
    else if(n==3)
    {
        scanf("%lf%lf%lf",&arr[0],&arr[1],&arr[2]);

        sort(arr,arr+3);

        a=arr[0];
        b=arr[1];
        c=arr[2];

        d=2*(b+c)-a-b-c;

        if(d<=0)
        {
            printf("NO\n");
            return 0;
        }

        df=d-a;
        md=(c+b)/2;
        mn=(a+b+c+d)/4;

       // printf("%lf %lf %lf\n",df,md,mn);

         if(df==md&&md==mn)
        {
            printf("YES\n");
            printf("%.0lf\n",d);
        }
        else
        {
            printf("NO\n");
        }

    }
    else if(n==4)
    {
        scanf("%lf%lf%lf%lf",&arr[0],&arr[1],&arr[2],&arr[3]);

        sort(arr,arr+4);

        a=arr[0];
        b=arr[1];
        c=arr[2];
        d=arr[3];

       // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

        df=d-a;
        md=(b+c)/2;
        mn=(a+b+c+d)/4;

        if(df==md&&md==mn)
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
