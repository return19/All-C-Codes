#include<stdio.h>

long long a[1000010];
long long fn[1000010];
long long fnp[1000010][2];
int main()
{
    long long n,l,i,j,k,r,sum=0,sum1=0,test,t,x,y;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%lld",&l);
        scanf("%lld",&r);
        l=l-1;
        r=r-1;
       fnp[i][0]=l;
       fnp[i][1]=r;
      /* for(j=l;j<=r;j++)
       {
        sum=sum+a[j];
       }
       fn[i]=sum;*/

    }

    scanf("%lld",&test);
    for(j=0;j<test;j++)
    {
     scanf("%lld",&t);
     scanf("%lld",&x);
     scanf("%lld",&y);
    if(t==1)
    {
        x=x-1;

        /*for(i=0;i<n;i++)
        {
            if(fnp[i][0]<=x&&fnp[i][1]>=x)
            {
                fn[i]=fn[i]+(y-a[x]);

            }
        }*/

         a[x]=y;
    }
    else
    {
        x=x-1;
        y=y-1;
        sum=0;
        /*for(i=x;i<=y;i++)
        {
            sum=sum+fn[i];
        }*/
        for(i=x;i<=y;i++)
        {
            for(k=fnp[i][0];k<=fnp[i][1];k++)
            {
                sum=sum+a[k];
            }
        }
        printf("%lld\n",sum);
    }
    }

    return 0;
}

