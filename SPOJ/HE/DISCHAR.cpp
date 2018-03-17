#include<map>
using namespace std;
#include<stdio.h>

 map<long long,long long> memo;

 char s[100110];

int main()
{
    long long test,i,n,sum;

    scanf("%lld",&test);

    for(i=1;i<=test;i++)
    {
        scanf("%s",s);
        n=0; sum=0;
        while(s[n]!='\0')
        {
            if(memo[s[n]]!=i)
            {
                memo[s[n]]=i;
                sum++;
            }
            n++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
