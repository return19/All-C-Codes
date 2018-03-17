#include<bits/stdc++.h>
using namespace std;

long long n;
priority_queue<long long> pq;

map<long long,long long> memo;
map<long long,long long>::iterator it;

int main()
{
    long long i,j,k;
    long long test,t;
    long long x;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            memo[x]++;
        }

        for(it=memo.begin();it!=memo.end();it++)
        {
            pq.push(it->second);
            //cout<<it->second<<endl;
        }
        long long ans=0;

        while(!pq.empty())
        {
            long long x=pq.top();
            pq.pop();

            //cout<<x<<" ";

            if(pq.empty())
            {
                ans+=x;
                break;
            }
            long long y=pq.top();
           // cout<<y<<endl;
            pq.pop();
            ans=ans + 1;
            x--;
            y--;
            if(x>0)
                pq.push(x);
            if(y>0)
                pq.push(y);
        }

        printf("%lld\n",ans);
        memo.clear();
    }

    return 0;
}










