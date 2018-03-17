#include<bits/stdc++.h>
using namespace std;

unsigned long long num[101000];
unsigned long long den[101000];
unsigned long long n;

unsigned long long s[10100000];

vector<unsigned long long> prime;
unsigned long long mx_num;

unsigned long long p_num[10100000];

unsigned long long max(unsigned long long x,unsigned long long y)
{
    if(x>y)
        return x;
    return y;
}

void sieve()
{
    unsigned long long i,j,k;
    s[0]=s[1]=1;

    for(i=2;i<=mx_num;i++)
    {
        if(s[i]==0)
        {
            prime.push_back(i);
            k=2;
            for(j=i;j<=mx_num;j=j*k)
            {
                s[j]=1;
                j++;
            }
        }
    }
}

unsigned long long power(unsigned long long x,unsigned long long y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;

    unsigned long long hf=power(x,y/2);

    if(y&1)
        return hf*hf*x;
    return hf*hf;
}

int main()
{
    unsigned long long i,j,k;
    unsigned long long test,t;
    unsigned long long c=0;

    unsigned long long ans_d,ans_n;

    unsigned long long mx_p;

    mx_num=1000010;
    sieve();

    scanf("%lld",&test);
    printf("%lld\n",test);

    for(t=0;t<test;t++)
    {
        mx_num=0;
        memset(p_num,0,sizeof(p_num));
        scanf("%lld",&n);

        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&num[i],&den[i]);
        }

        mx_p=0;

        for(i=0;i<n;i++)
        {
            unsigned long long temp=den[i];
            for(j=0;prime[j]*prime[j]<=temp;j++)
            {
                c=0;
                while(temp%prime[j]==0)
                {
                    c++;
                    temp/=prime[j];
                }
                p_num[prime[j]]=max(p_num[prime[j]],c);

                if(p_num[prime[j]]>0)
                    mx_p=max(mx_p,prime[j]);
            }
            if(temp>1){
                p_num[temp]=max(p_num[temp],1);
                mx_p=max(mx_p,temp);
            }
        }

        ans_d=1;
        for(i=0; prime[i]<=mx_p && i<prime.size();i++)
        {
           // cout<<prime[i]<<" "<<p_num[prime[i]]<<endl;
            ans_d *= power(prime[i],p_num[prime[i]]);
        }

        ans_n=0;
        unsigned long long mul;
        for(i=0;i<n;i++)
        {
            mul=ans_d/(__gcd(den[i],ans_d));
            ans_n = ans_n + num[i]*(mul);
        }

        unsigned long long div=__gcd(ans_n,ans_d);

        ans_n/=div;
        ans_d/=div;

        printf("%lld %lld\n",ans_n,ans_d);
    }

    return 0;
}















