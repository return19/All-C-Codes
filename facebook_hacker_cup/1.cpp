#include<bits/stdc++.h>
using namespace std;

map< pair<long long,long long>,long long > memo;
map< pair<long long,long long>,long long >::iterator it;

long long sq(long long x)
{
    return x*x;
}

long long n;

long long arrx[2010];
long long arry[2010];

long long dist(long long x,long long y)
{
    return (sq(abs(arrx[x]-arrx[y])) + sq(abs(arry[x]-arry[y])));
}

int main()
{
    long long test,i,j,k,t;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++){
            scanf("%lld%lld",&arrx[i],&arry[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long temp=dist(i,j);
                   // cout<<i<<" "<<j<<" : "<<temp<<endl;
                    memo[make_pair(i,temp)]++;
                }
            }
        }

        long long ans=0;

        for(it=memo.begin();it!=memo.end();it++)
        {
            long long num=it->second;
            ans = ans + ((num)*(num-1))/2;
        }

        printf("Case #%lld: %lld\n",t+1,ans);
        memo.clear();
    }

    return 0;
}














