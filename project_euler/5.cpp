#include<bits/stdc++.h>
using namespace std;

long long pfact[50];

int main()
{
    long long test,i,j,k,t;
    long long n;
    long long sq;
    long long c;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        memset(pfact,0,sizeof(pfact));

        scanf("%lld",&n);
        long long temp;
        for(i=2;i<=n;i++)
        {
            sq=sqrt(i);

            temp=i;

            for(j=2;j<=sq;j++)
            {
                if(temp%j==0)
                {
                    c=0;

                    while(temp%j==0)
                    {
                        c++;
                        temp=temp/j;
                    }

                    pfact[j]=max(pfact[j],c);
                }
            }

            if(temp>1)
                pfact[temp]=max(pfact[temp],(long long)1);
        }

        long long ans=1;

        for(i=2;i<=n;i++)
            ans *= pow(i,pfact[i]);

        printf("%lld\n",ans);

    }

    return 0;
}
