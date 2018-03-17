#include<bits/stdc++.h>
using namespace std;

long long check(long long x,long long y,long long a,long long b)
{
    if(x*y != (a+b))    return 0;

    if(a%y==0 && b%y==0)
    {
        return 1;
    }

    if(a%x==0 && b%x==0)
        return 1;
    return 0;
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long r,c;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld%lld%lld",&r,&c,&x,&y,&z);

        if(r*c != (x+y+z)){
            printf("No\n");
            continue;
        }
        long long ans=0;
        if(x%c==0 && check(r - x/c , c,y,z))    ans=1;
        if(y%c==0 && check(r - y/c , c,x,z))    ans=1;
        if(z%c==0 && check(r - z/c , c,x,y))    ans=1;

        if(x%r==0 && check(r , c - x/r , y,z )) ans=1;
        if(y%r==0 && check(r , c - y/r , x,z )) ans=1;
        if(z%r==0 && check(r , c - z/r , x,y )) ans=1;

        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}













