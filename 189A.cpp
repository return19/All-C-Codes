#include<bits/stdc++.h>
using namespace std;

int a,b,c;

int memo[1010000];
int base[1010000];

int solve(int n)
{
    if(n==0)
        return 0;

    if(n<a && n<b && n<c)
        return INT_MIN;

    //remove comment to memoize
    //if(base[n]!=0)  return memo[n];
   // base[n]=1;

    int na,nb,nc;

    na=solve(n-a);
    nb=solve(n-b);
    nc=solve(n-c);

    if(na==INT_MIN && nb==INT_MIN && nc==INT_MIN)
        return INT_MIN;
    if(na!=INT_MIN) na++;
    else    na=0;

    if(nb!=INT_MIN) nb++;
    else    nb=0;

    if(nc!=INT_MIN) nc++;
    else    nc=0;

    return memo[n]=max(na,max(nb,nc));
}

int main()
{
    int n;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    printf("%d\n",solve(n));
    return 0;
}
