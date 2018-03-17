#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;
map<long long,long long>::iterator it;
int main()
{
    long long test,i,j,k,n,s,sum;
    long long count1=0;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        scanf("%lld%lld",&n,&s);
        j=1;

        memo[j]++;
        n--;
        j++;
        sum=1;
        while(n>0&&s>0)
        {
            if(sum+j<=s&&(s-sum-j)>=(n-1))
            {
                memo[j]++;
                sum=sum+j;
                j++;
                n--;
            }
            else
            {
                j--;
            }

            if((s-sum)==n)
            {
                memo[1]=memo[1]+n;
                break;
            }
        }
        count1=0;
        for(it=memo.begin();it!=memo.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<endl;
            if(it->second>1)
                count1=count1+(it->second-1);
        }

        printf("%lld\n",count1);
    }

    return 0;
}
