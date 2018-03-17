#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k,t;

    int n,m;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        if(n==1)
        {
            printf("-1 -1\n");
        }
        else if(n==2)
        {
            if(m==1)
            {
                printf("1 2\n");
            }
            else
                printf("-1 -1\n");
        }
        else
        {
            if(m==n)
            {
                for(i=1;i<n;i++)
                    printf("%d %d\n",i,i+1);
                printf("%d 1\n",n);
            }
            else
            {
                printf("-1 -1\n");
            }
        }
    }

    return 0;
}

