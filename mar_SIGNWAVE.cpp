#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j;
    long long s,c,k;
    long long test;
    long long p,ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        ans=0;

        scanf("%lld%lld%lld",&s,&c,&k);

        if(s==0&&k>1)
        {
            printf("0\n");
            continue;
        }

        if(s==0&&c==0)
        {
            printf("0\n");
            continue;
        }



        if(k==1)
        {
            if(s==0)
            {
                p=1;
                for(j=0;j<c;j++)
                {
                    ans=ans+pow(2,p);
                    p++;
                }

            printf("%lld\n",ans);
            continue;
            }

            if(s!=0)
            {
                ans=pow(2,s)+1;
            }
            p=0;
            for(j=0;j<c-s+1;j++)
            {
                ans=ans+pow(2,s+p);
                p++;
            }

            printf("%lld\n",ans);
            continue;
        }

        if(s+1-k>0)
        {
            ans=pow(2,s+1-k);

            if(c>=s+1-k)
            {
                ans=ans*2;
            }
            ans=ans+1;
            printf("%lld\n",ans);
            continue;
        }
        else
        {
             printf("0\n",ans);
        }


    }

    return 0;
}











