#include<bits/stdc++.h>
using namespace std;

long long n,m;
map<long long,long long> memo;
map<long long,long long>::iterator it;

int main()
{
    long long i,j,k,sf,nf,q;
    long long sum;
    char c[2];
    scanf("%lld",&n);
    memo.clear();
    for(i=0;i<n;i++)
    {

        scanf("%lld%lld",&sf,&nf);
        memo[sf]=nf;
    }
    scanf("%lld",&m);
    //cout<<"m "<<m<<endl;
    for(i=0;i<m;i++)
    {   //cout<<i<<" ";
        sum=0;
        scanf("%s",c);
        scanf("%lld",&q);
        if(c[0]=='+')
        {
            memo[q]++;
        }
        else if(c[0]=='-')
        {
            memo[q]--;
        }
        else if(c[0]=='?')
        {
            sum=0;
            for(it=memo.begin();it!=memo.end();it++)
            {
                sum=sum+(q%(it->first))*(it->second);
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
