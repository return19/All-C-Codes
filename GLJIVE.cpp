#include<bits/stdc++.h>
using namespace std;


long long pos(long long a)
{
    if(a>=0)
        return a;
    else
        return a*(-1);
}

int main()
{
    long long i,j,k,ans1,ans2;
    long long temp,flag=0;

    ans1=0;
    ans2=0;
    for(i=0;i<10;i++)
    {
        scanf("%lld",&temp);

        if(ans1<100&flag==0)
        {
            ans1=ans1+temp;
            if(ans1>=100){
                flag=1;
                ans1=ans1-temp;
                ans2=ans1+temp;
            }
        }
    }

    if(pos(100-ans1)<pos(ans2-100))
    {
        printf("%lld",ans1);
    }
    else
    {
        printf("%lld",ans2);
    }

    return 0;
}
