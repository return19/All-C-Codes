#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;

    int n,m;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);

        if(abs(n-m)>=2)
        {
            printf("Player A wins\n");
        }
        else
        {
            printf("Player B wins\n");
        }
    }

    return 0;
}
