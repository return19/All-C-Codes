#include<bits/stdc++.h>
using namespace std;
  long long cur=1;
     long long f=0;
     long long i,j,k;
     long long l,r;
int main()
{


    scanf("%lld%lld%lld",&l,&r,&k);


    for(;;)
    {
        if(l<=cur && cur<=r)
        {
            printf("%lld ",cur);
            f=1;
        }

        if(LLONG_MAX/k<cur || cur>r)
            break;
        cur=cur*k;
    }

    if(f==0)
    {
        printf("-1\n");
        return 0;
    }


    return 0;
}
