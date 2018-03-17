#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

map<long long,long long> memo;
map<long long,long long> memo1;
map<long long,long long>::iterator it;


long long power(long long x, unsigned long long y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2)%M;
    if (y%2 == 0)
        return (temp*temp)%M;
    else
        return (x*temp*temp)%M;
}

int main()
{
    long long test,i,j,k,x,n,count1=0;
    long long sq,sum;
    long long count2=0,temp;
    long long c1,c2;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();

        sum=1;
        count1=0;
        count2=0;

        scanf("%lld",&n);

        scanf("%lld",&n);
        sq=sqrt(n);

        for(j=2;j<=sq;j++)
        {
            if(n%j==0)
            {
                count1++;
                while(n%j==0)
                {
                    memo[j]++;
                    n=n/j;
                }
                if(memo[j]%3==0)
                    count2++;
            }
        }
        if(n>1)
        {
            memo[n]++;
            count1++;
        }

        c1=count1;
        c2=count2;

        j=2;
        while(count1!=count2)
        {
            x=j;
            count1=c1;
            count2=c2;
          memo1.clear();

          sq=sqrt(j);

          for(k=2;k<=sq;k++)
          {
              if(x%k==0)
              {
                  memo1[k]=memo[k];

                  if(memo1[k]%3==0&&memo1[k])
                  {
                      count2--;
                  }

                  if(!memo1[k])
                    count1++;

                  while(x%k==0)
                  {
                      memo1[k]++;
                      x=x/k;
                  }

                  if(memo1[k]%3==0)
                    {count2++;}
                    else
                        break;

              }
          }

          if(x>1)
          {
              memo1[x]=memo[x]+1;
              if(memo1[x]%3==0)
                count2++;

              if(memo[x]==0)
                count1++;
          }

            j++;
        }

        //cout<<"j:"<<j<<endl;
        sum=1;
        for(it=memo1.begin();it!=memo1.end();it++)
        {
                memo[it->first]=it->second;

        }

        for(it=memo.begin();it!=memo.end();it++)
        {
            sum=(sum*power(it->first,it->second))%M;
        }

        printf("%lld\n",sum);

    }

    return 0;
}
