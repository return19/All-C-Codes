#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int a,b;
    int h1,h2;

    scanf("%d%d",&h1,&h2);
    scanf("%d%d",&a,&b);

    h1 += 8*a;

    if(h1>=h2)
    {
        printf("0\n");
        return 0;
    }

    if(a<=b)
    {
        printf("-1\n");
        return 0;
    }

    for(i=1;i<=2000000;i++)
    {
        h1 -= 12*b;
        h1 += 12*a;

        if(h1>=h2)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}














