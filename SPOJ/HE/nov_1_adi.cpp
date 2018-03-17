#include<map>
using namespace std;

#include<stdio.h>

map<char,int> memo;

char a[1000000];

int main()
{
    long long i,t,x,j;

    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%s",a);
        x=0;
        for(i=0;a[i];i++)
        {
            if(memo[a[i]]!=j)
            {
                memo[a[i]]=j;
                x++;
            }
        }

        printf("%lld\n",x);
    }
    return 0;
}
