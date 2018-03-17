#include<bits/stdc++.h>
using namespace std;

int a[5100];
int memo[5100];

int main()
{
    int n,i,j,k;
    int temp;
    scanf("%d",&n);


    if(n==1)
    {
        printf("1\n1\n");
        return 0;
    }
    else if(n==2)
    {
        printf("1\n1\n");
        return 0;
    }
    else if(n==3)
    {
        printf("2\n1 3\n");
        return 0;
    }
    else if(n==4)
    {
        printf("3\n1 4 2\n");
        return 0;
    }
    else
    {
        printf("%d\n",n);
    }


    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }

    for(i=4;i<=n;i=i+3)
    {
        memo[i]=1;
        memo[i-3]=1;

        temp=a[i];
        a[i]=a[i-3];
        a[i-3]=temp;

    }

    for(i=5;i<=n;i=i+2)
    {
        if(memo[i])
        {
            i=i+2;
            if(i<=n){
            temp=a[i];
            a[i]=a[i-4];
            a[i-4]=temp;
            }

            continue;
        }

        temp=a[i];
        a[i]=a[i-2];
        a[i-2]=temp;
    }

    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
