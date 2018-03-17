#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k,n;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        if(n%2==0)
        {
            printf("%d\n",n/2);
        }
        else
        {
            printf("%d\n",n/2+1);
        }
    }

    return 0;
}
