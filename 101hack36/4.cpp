#include<bits/stdc++.h>
using namespace std;

string s;
map< pair<long long,long long>,long long> memo;
map<char,long long> memo1;



long long M=1e9 + 7,MOD1=321321211,MOD2=1e9 + 7;

long long power(long long x,long long y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;

    long long hf=power(x,y/2);

    if(y&1) return (((hf*hf)%M)*x)%M;
    return ((hf*hf)%M);
}

int main()
{
    long long i,j,k;
    long long n;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();
        long long ans=0;
        cin>>s;
        n=s.length();
        for(i=0;i<n;i++)
        {
            long long hsh1=0,hsh2=0;
            memo1.clear();

            for(j=i;j<n;j++)
            {
                hsh1=(hsh1*43 + (s[j]-'a'+1))%MOD1;
                hsh2=(hsh2*43 + (s[j]-'a'+1))%MOD2;
                memo1[s[j]]=1;

                if(memo.find(make_pair(hsh1,hsh2))==memo.end())
                {
                    memo[make_pair(hsh1,hsh2)]=1;

                    ans= (ans + power(j-i+1,memo1.size()))%M;
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
