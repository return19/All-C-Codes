#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y;
    long long a,b;

    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&a,&b);
        scanf("%lld%lld",&x,&y);

        long long ans=0;

        if(a>=x && b>=y)
            ans=1;
        swap(x,y);
        if(a>=x && b>=y)
            ans=1;

        if(a>b)
            swap(a,b);
        if(x>y)
            swap(x,y);

        long long mx_x = 2*(b-y)*b;
        mx_x = mx_x/a;

        if(x<=mx_x)
            ans=1;

        if(ans==0)
            printf("Box cannot be dropped.\n");
        else
            printf("Escape is possible.\n");
    }

    return 0;
}
