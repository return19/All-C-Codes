#include<bits/stdc++.h>
using namespace std;

double PI=3.14159265359;

int main()
{
    long long test,i,j,k,n;
    double ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        if(n==0||n==1)
        {
            printf("1\n");
            continue;
        }

        ans=floor((log(2*PI*n)/2+n*(log(n)-1))/log(10))+1;
        //cout<<ans<<endl;

        printf("%.0f\n",ans);
    }

    return 0;
}
