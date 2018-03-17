#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d%d",&n,&m,&k);

        if(n>m)
            swap(n,m);

        int x=(m-n);
        if(k>x)
        {
            n=m;
            k=k-x;
            printf("0\n");
        }
        else
        {
            n=n+k;
            printf("%d\n",m-n);
        }

    }

    return 0;
}
















