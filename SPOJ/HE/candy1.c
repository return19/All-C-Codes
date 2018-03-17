#include<stdio.h>
long long a[100010];
int main()
{
    long long n,i,j,sum=0,move,candy;

    scanf("%lld",&n);
    while(n!=-1)
    {
        sum=0; move=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum=sum+a[i];
        }
        if(sum%n!=0)
        {
            printf("-1\n");
        }
        else
        {
            candy=sum/n;
            for(i=0;i<n;i++)
            {
                if(a[i]>candy)
                {
                    move=move+(a[i]-candy);
                }

            }
            printf("%lld\n",move);
        }
        scanf("%lld",&n);
    }
    return 0;
}
