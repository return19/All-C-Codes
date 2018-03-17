#include<stdio.h>
#include<conio.h>

long long int fact(long long int n)
{
    long long int f=1;
    while(n>0)
    {
        f=f*n;
        n--;
    }
    return f;

}

int main()
{
    int n[1000],k[100],t;
    int i,j;
    long long int f,f1;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n[i],&k[i]);

    }

    for(i=0;i<t;i++)
    { f=fact(n[i]);
        for(j=0;j<k[i]-1;j++)
        {
            f=fact(f);

        }
        printf("%d\n",f%107);
    }
    return 0;
}
