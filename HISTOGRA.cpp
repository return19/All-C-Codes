#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long n;

stack<long long> s;

long long maxhisto()
{
    long long i,j,k;
    long long ans=0;

    for(i=0;i<n;i++)
    {
        if(s.empty() || (arr[s.top()]<=arr[i]))
            s.push(i);
        else{

            while(!s.empty() && arr[s.top()]>arr[i])
            {
                long long temp=s.top();
                s.pop();

                if(s.empty())
                    ans=max(ans,arr[temp]*(i));
                else
                    ans=max(ans , (i-s.top()-1)*arr[temp]);
            }
            s.push(i);
        }
    }


    while(!s.empty())
    {
        long long temp=s.top();
        s.pop();

        if(s.empty())
            ans=max(ans,arr[temp]*(n));
        else
            ans=max(ans,(n-s.top()-1)*arr[temp]);
    }

    return ans;

}

int main()
{
    long long i,j,k;

    scanf("%lld",&n);

    while(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        long long ans=maxhisto();

        printf("%lld\n",ans);

        scanf("%lld",&n);
    }

    return 0;
}
