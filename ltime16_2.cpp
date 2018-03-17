#include<bits/stdc++.h>
using namespace std;

long long arr[100010],S=-1;
long long sv[100010];
map<long long,long long> memo;
map<long long,long long>::iterator it;
void sieve()
{
    long long i,j,k;

    for(j=2;j<1010;j++)
    {
        if(sv[j]!=1)
        {
            arr[++S]=j;
            k=2;
            for(i=j*k;i<1010;k++,i=j*k)
            {
                sv[i]=1;
            }
        }
    }
}

int main()
{
    long long test,i,j,k,n,temp;
    scanf("%lld",&test);

    sieve();
    /*for(i=0;i<100;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&temp);
            long long count1=0,sq=(long long)sqrt(temp);
            for(k=0;arr[k]<=sq;k++)
            {
                count1=0;
                if(temp%arr[k]==0)
                {
                    while(temp%arr[k]==0)
                    {
                        count1++;
                        temp=temp/arr[k];
                    }
                    if(memo[arr[k]]<count1)
                        memo[arr[k]]=count1;
                }
            }
            if(temp>1)
            {
                if(memo[temp]==0)
                    memo[temp]=1;
            }
        }
        long long sum=0;
        for(it=memo.begin();it!=memo.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<endl;
            sum=sum+it->second;
        }
        printf("%lld\n",sum);
        memo.clear();
    }

    return 0;
}
