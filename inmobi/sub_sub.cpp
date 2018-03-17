#include<bits/stdc++.h>
using namespace std;

char str[101000];
char z[101000];

int M=10000000007;

long long n,m;

long long inside(string str,char z[])
{
    long long n=str.length();

    long long i,j,k;

    for(i=0;i<n;i++)
    {
        if(str[i]==z[0])
        {
            for(j=i; j<n && j<i+m ;j++)
            {
                if(str[j]!=z[j-i])
                    break;
            }

            if(j==i+m)
                return 1;
        }
    }

    return 0;
}

long long c;

map< pair<long long,long long>,long long > memo;

long long solve(long long idx,long long x)
{
    c++;

    long long i,j,k;

    if(x==0)
        return 1;

    if(memo.find(make_pair(idx,x))!=memo.end())
        return memo[make_pair(idx,x)];

    string temp;

    long long ans=0;

    for(i=idx;i<n;i++)
    {
        temp="";

        for(j=i;j<n;j++)
        {
            temp.push_back(str[j]);

            if(inside(temp,z))
                ans = (ans + solve(j+1,x-1))%M;
        }
    }

    return memo[make_pair(idx,x)]=ans;
}

int main()
{
    long long i,j,k;

    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        c=0;

        scanf("%s",str);
        scanf("%s",z);

        n=strlen(str);
        m=strlen(z);

        //cout<<n<<" "<<m<<endl;

        long long ans=0;

        for(i=1;i<=n/m+1;i++)
        {
            ans = (ans + solve(0,i))%M;
        }

        printf("%lld\n",ans);

        //cout<<c<<endl;

        memo.clear();
    }

    return 0;
}
