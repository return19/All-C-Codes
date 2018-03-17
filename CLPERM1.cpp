#include<bits/stdc++.h>
using namespace std;
map<long long,long long> memo;
long long n,k,memo_count,sum_k;
long long check()
{
    long long i,j,sum=0;
    memo_count=0;
    for(i=1;i<=n;i++)
    {
        if(!memo[i])
        {
            if(sum+1<i)
            {
                return sum;
            }
            else
            {
                sum=sum+i;
            }
        }
        else
        {
           memo_count++;
           if(sum<i)
           {
               return (sum+1);
           }
           if(memo_count==k)
           {
               return ((n*(n+1))/2-sum_k+1);
           }
        }
    }
}


int main()
{
    long long test,i,j,num,flag,index;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum_k=0;    flag=0;
        memo.clear();
        scanf("%lld%lld",&n,&k);
        if(k!=0)
        for(j=0;j<k;j++)
        {
            scanf("%lld",&num);
            if(num>2)
            {
                memo[num]=1;
                sum_k=sum_k+num;
            }
            else if(num==1)
            {
                printf("Chef\n");
                flag=1;
                break;

            }
            else if(num==2)
            {
                printf("Mom\n");
                flag=1;
                break;
            }

        }
        else
        {
            if(((n*(n+1))/2)%2!=0){
                printf("Mom\n");
                continue;
            }
            else
            {
                printf("Chef\n");
                continue;
            }
        }

        if(flag!=1)
        {
            index=check();
            cout<<index<<endl;
            if(index%2!=0)
            {
                printf("Chef\n");
            }
            else
            {
                printf("Mom\n");
            }
        }

    }
    return 0;
}













