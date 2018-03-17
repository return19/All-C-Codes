#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n,m,s;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld",&n,&m,&s);

        m=m%n;
        if(m!=0){
            s--;
            s=(s+m-1)%n;
            s++;
        }else{
            if(s==1)
                s=n;
            else
                s--;
        }

        printf("%lld\n",s);
    }

    return 0;
}
