#include<bits/stdc++.h>
using namespace std;

char str[2010];

int main()
{
    unsigned long long test,i,j,k,t;
    unsigned long long N,x;
    unsigned long long ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);
        scanf("%lld",&N);

        N=N*12-1;
        x=0;

        j=0;
        while(str[j]!='\0')
        {
            if(str[j]=='S')
            {
                x=x+1;
            }
            else if(str[j]=='T')
            {
                x=x+2;
            }
            j++;
        }

        t=N/x;

        ans=(N+1)*t-(x*(t*(t+1)))/2;

        printf("%lld\n",ans);
    }

    return 0;
}











