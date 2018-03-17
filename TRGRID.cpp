#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,n,m,i;
    int n1,m1;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);

        n1=n%2;
        m1=m%2;

        if(n1==0&&m1==1)
        {

            if(n>m)
            {
                printf("D\n");
            }
            else
            {
                printf("L\n");
            }
        }
        else if(n1==1&&m1==0)
        {

            if(n>m)
            {
                printf("U\n");
            }
            else
            {
                printf("R\n");
            }
        }
        else if(n1==0&&m1==0)
        {
           if(n==m)
            {
                printf("L\n");
            }
            else if(n>m)
            {
                printf("U\n");
            }
            else
            {
                printf("L\n");
            }
        }
        else
        {
            if(n==m)
            {
                printf("R\n");
            }
            else if(n>m)
            {
                printf("D\n");
            }
            else
            {
                printf("R\n");
            }
        }
    }

    return 0;
}
