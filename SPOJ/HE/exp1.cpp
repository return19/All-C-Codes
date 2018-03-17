#include<map>
using namespace std;
#include<stdio.h>
map<int,long long> memo;
long long fact(int n)
{

    long long t;
    if(memo[n])
    {
        return memo[n];
    }
    else
    {
        if(n==0||n==1)
        {
            memo[n]=1;
            return 1;
        }
        else
        {
            memo[n]=n*fact(n-1);
            return memo[n];
        }
    }


}

int main()
{
    int test,n,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        printf("%lld\n",fact(n));
    }
    return 0;
}
