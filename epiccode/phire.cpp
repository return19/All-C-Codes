#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,p,x;
    long long ans=-1,idx;
    long long temp;
    long long i,j,k;

    scanf("%lld%lld%lld",&n,&p,&x);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&temp);

        if(temp*(p-i*x)>ans)
        {
            idx=i+1;
            ans=temp*(p-i*x);
        }
    }

    printf("%lld\n",idx);


    return 0;
}
