#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n,m;

    scanf("%d%d",&n,&m);

    k=0;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<m;j++)
                printf("#");
            printf("\n");
        }
        else
        {
            if(k)
            {
                printf("#");
                for(j=1;j<m;j++)
                    printf(".");
                printf("\n");
                k=1-k;
            }
            else
            {
                for(j=0;j<m-1;j++)
                    printf(".");
                printf("#");
                printf("\n");
                k=1-k;
            }
        }
    }
    return 0;
}
