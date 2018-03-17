#include<bits/stdc++.h>
using namespace std;

vector<long long> odd;

int main()
{
    long long i,j,k;
    long long n,x;
    long long sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        if(x%2==0)
            sum+=x;
        else
            odd.push_back(x);
    }

    sort(odd.begin(),odd.end(),greater<long long>());

    if(odd.size()%2==0)
    {
        for(i=0;i<odd.size();i++)
            sum+=odd[i];
    }
    else
    {
        for(i=0;i<odd.size()-1;i++)
            sum+=odd[i];
    }

    printf("%lld\n",sum);

    return 0;
}



















