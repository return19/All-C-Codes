#include<bits/stdc++.h>
using namespace std;

long long arr[501000];

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;

    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        long long j=1;
        long long ans=0;
        long long cur;

        for(i=0;i<n;)
        {
            if(j==1)
            {
                j++;
                cur=arr[i];
                i++;
            }
            else if(j==2 || j==3 || j==4)
            {
                if(arr[i]<=cur)
                {
                    ans=ans+(4-j+1);
                    j=1;
                    continue;
                }

                if(arr[i]-cur<=10)
                {
                    cur=arr[i];
                    i++;
                }
                else
                {
                    cur=cur+10;
                    ans++;
                }

                if(j==4)
                    j=1;
                else
                    j++;
            }
        }

        if(j!=1)
        {
            ans=ans+(4-j+1);
        }

        printf("Case #%lld: %lld\n",t+1,ans);
    }

    return 0;
}



















