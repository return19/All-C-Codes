#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;
    int n;
    int a,b;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&a,&b);

        if(a%2!=0&&b%2!=0)
        {
            printf("Vanka\n");
        }
        else
        {
            printf("Tuzik\n");
        }
    }

    return 0;
}

