#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;
    int n,m;
    int t;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);

        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
                scanf("%d",&t);
        }

        if(n%2==0)
        {
            printf("%d\n",n/2);

            for(j=1;j<=n;j=j+2)
            {
                printf("%d 1 %d %d\n",j,j,m);
            }
        }
        else
        {
            printf("%d\n",m/2);

            for(j=1;j<=m;j=j+2)
            {
                printf("1 %d %d %d\n",j,n,j);
            }
        }

    }


    return 0;
}
