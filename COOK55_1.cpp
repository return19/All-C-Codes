#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k,b,ans=0,inc=1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        ans=0;
        inc=1;
        scanf("%lld",&b);
        if(b==1)
        {
            printf("0\n");
            continue;
        }
        j=2;
        while(1)
        {
            if(b==j)
            {
                break;
            }
            j++;
            if(b==j)
            {
                break;
            }
            j++;
            ans=ans+inc;
            inc=inc+1;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
