#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n,x;
    long long d,ans;
    string s;
    scanf("%lld%lld",&n,&x);

    ans=0;

    for(i=0;i<n;i++)
    {
        cin>>s;
        cin>>d;

        if(s[0]=='+'){
            x+=d;
        }else{
            if(x>=d)
                x-=d;
            else
                ans++;
        }
    }

    printf("%lld %lld\n",x,ans);
    return 0;
}
