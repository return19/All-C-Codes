#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
long long arr[110];

long long ans[310];

vector<long long> inc,p;

int main()
{
    long long i,j,k;
    long long n;
    long long t;

    scanf("%lld%lld",&n,&t);

    inc.resize(301);
    p.resize(301);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    long long res=0,res1=0;

    long long chk=0;

    for(i=0;i<t;i++)
    {
        for(j=0;j<n;j++)
        {
            long long temp=0;
            for(k=1;k<=arr[j];k++)
            {
                temp=max(temp,1+arr[k]);
            }

            if(temp>ans[arr[j]])
            {
                inc[arr[j]]=temp-ans[arr[j]];
                ans[arr[j]]=temp;
            }
        }
        chk=0;
        for(k=1;k<=300;k++)
        {
            if(inc[k]!=p[k])
                chk=1;
        }

        if(!chk)
        {
            int x=i+1;
            res1=0;
            if(x<t)
            {
                for(k=1;k<=300;k++){
                    res1=max(res1,ans[k] + ((t-x)*(inc[k])));
                }
            }

        }
        swap(p,inc);
    }

    res=0;
    for(k=1;k<=300;k++)
        res=max(res,ans[k]);

    printf("%lld %lld\n",res,res1);

    return 0;
}












