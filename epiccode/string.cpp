#include<bits/stdc++.h>
using namespace std;

char str[1100000];

map<char,long long> memo;
map<char,long long>::iterator it;

map<char,long long> ans;

int main()
{
    long long n,i,j,k;
    long long sum=0;

    scanf("%lld",&n);

    scanf("%s",str);

    for(i=0;i<n;i++)
    {
        ans[str[i]]+= 1 + memo[str[i]];

        memo[str[i]]++;

    }


    for(it=ans.begin();it!=ans.end();it++)
    {
        sum+=it->second;
    }


    printf("%lld\n",sum);



    return 0;
}
