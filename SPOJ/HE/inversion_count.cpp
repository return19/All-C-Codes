#include<stdio.h>

long long a[200010];

int main()
{
    long long test,n,i,j,k,sum=0;
    char x;
    scanf("%lld",&test);


    for(i=0;i<test;i++)
    {x=getchar();
        sum=0;
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }

        for(j=0;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[j]>a[k])
                {
                    sum++;
                }
            }
        }
        printf("%lld\n",sum);

    }
    return 0;
}
