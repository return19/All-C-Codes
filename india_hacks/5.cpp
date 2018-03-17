#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

long long mx=INT_MIN;
long long cnt=1;

long long arr[101000];

void solve(long long idx,long long k,long long pro)
{
    long long i,j;

    if(idx<0)
    {
        if(k==0){
            memo[pro]=-1;
            mx=max(mx,pro);
        }
        return;
    }

    solve(idx-1,k,pro);

    for(i=1;i<=k;i++){
        pro=pro*arr[idx];
        solve(idx-1,k-i,pro);
    }
}

int main()
{
    long long i,j;
    long long n,k,m;
    long long x,y;

    scanf("%lld%lld%lld",&n,&k,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld",&x);
        memo[x]=-1;
    }

    for(i=0;i<n;)
    {
        //cout<<i<<" "<<cnt<<endl;
        if(i<k){
            if(memo.find(cnt)==memo.end())
            {
                arr[i]=cnt;
                cnt++;
                i++;
            }
            else
                cnt++;
        }
        else
        {

                if(memo.find(cnt)==memo.end())
                {
                    arr[i]=cnt;
                    cnt++;
                    i++;
                }
                else
                    cnt++;

                solve(i-1,k,1);

        }
    }

    for(i=0;i<n;i++)
        printf("%lld ",arr[i]);

    return 0;
}
