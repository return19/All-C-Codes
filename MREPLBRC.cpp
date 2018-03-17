#include<bits/stdc++.h>
using namespace std;

long long n;

char str[310];

long long M=1000000;

map< pair<long long,long long>,long long > memo;

long long solve(long long x,long long y)
{
    if(x>y){
        //cout<<x<<" "<<y<<" : "<<1<<endl;
        return 1;
    }

    if(str[x]==')'||str[x]=='}'||str[x]==']')
        return 0;

    if((y-x+1)%2!=0)
        return 0;

    if(memo.find(make_pair(x,y))!=memo.end())
        return memo[make_pair(x,y)];

    long long i,j,k;

    long long ans=0;

    for(i=x;i<=y;i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            continue;

        if(str[i]=='?')
        {
            if(str[x]=='?')
            {
                ans =  (ans + 3*solve(x+1,i-1)*solve(i+1,y))%M;
            }
            else
                ans = (ans + solve(x+1,i-1)*solve(i+1,y))%M;
        }
        else if(str[x]=='?')
        {
            ans = (ans + solve(x+1,i-1)*solve(i+1,y))%M;
        }
        else if((str[i]==')'&&str[x]=='(')||(str[i]=='}'&&str[x]=='{')||(str[i]==']'&&str[x]=='['))
        {
            ans = (ans + solve(x+1,i-1)*solve(i+1,y))%M;
        }
    }

    //cout<<x<<" "<<y<<" : "<<ans<<endl;

    return memo[make_pair(x,y)]=ans%M;
}

int main()
{
    long long i,j,k;

    scanf("%lld",&n);

    scanf("%s",str);

    long long ans=solve(0,n-1);

    if(ans%100000==ans)
        printf("%lld\n",ans);
    else
    {
        if(ans>99999)
        {
            ans=ans%100000;
            long long temp=ans;
            long long c=0;

            while(temp!=0)
            {
                c++;
                temp/=10;
            }

            for(i=0;i<5-c;i++)
                printf("0");
            printf("%lld",ans%100000);

        }
        else
            printf("%lld",ans);
    }


    return 0;
}












