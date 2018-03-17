#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;
map<long long,long long>::iterator it;

int main()
{
    long long test,i,j,n,k,p,temp,ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        scanf("%lld%lld%lld",&n,&k,&p);

        for(j=0;j<k;j++)
        {
            scanf("%lld",&temp);
            memo[temp]=1;
        }
        long long flag=0;
        ans=0;

        for(it=memo.begin();it!=memo.end();it++)
        {
            if(it->first>p)
            {
                while(ans!=0){
                temp=0;
                for(j=1;j<=ans;j++)
                {
                    p++;
                    if(memo[p])
                        temp++;
                }
                ans=temp;
                }

                if(p>n)
                {
                    flag=1;
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n",p);
                }
                flag=1;
                break;
            }
            ans++;
        }

        if(flag==0)
        {
            if(p+k<=n)
            {
                printf("%d\n",p+k);
            }
            else{
            printf("-1\n");
            }
        }
        /*for(j=1;j<=n;j++)
        {
            if(memo[j]!=1)
                ans++;

            if(ans==p)
            {
                flag=1;
                printf("%lld\n",j);
                break;
            }
        }
        if(flag==0)
        {
            printf("-1\n");
        }*/



    }

    return 0;
}
