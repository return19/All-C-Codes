#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int test,t;
    int n,m;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        if(n%4==0)
        {
            printf("Tuzik\n");
        }
        else if(n%4==1)
        {
            if(m-1<0)
            {
                 printf("Tuzik\n");
            }

            if((m-1)%3==0)
            {
                printf("Vanya\n");
            }
            else
                printf("Tuzik\n");
        }
        else if(n%4==2)
        {
            if(m-2<0)
            {
                 printf("Tuzik\n");
                 continue;
            }

            if((m-2)%3==0)
            {
                printf("Vanya\n");
            }
            else
                printf("Tuzik\n");
        }
        else if(n%4==3)
        {
            if((m)%3==0)
            {
                printf("Vanya\n");
            }
            else
                printf("Tuzik\n");
        }
    }

    return 0;
}

