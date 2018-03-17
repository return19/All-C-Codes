#include<bits/stdc++.h>
using namespace std;

unordered_map<string,long long> memo;


string str;

long long table[110000];
long long ncr[5010][5010];
long long ans[5010];

long long n,q,K;
long long len;
long long M=1000000007;

void calc()
{
    long long i,j,k;

    for(i=0;i<=5000;i++)
    {
        ncr[i][0]=1;
        ncr[i][1]=i;
    }

    for(i=2;i<=5000;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(i==j)
                ncr[i][j]=1;
            else
                ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%M;
        }
    }
}

void solve()
{
    long long i,j,k,ans;

    /*for(it=memo.begin();it!=memo.end();it++)
    {
       // cout<<it->first<<" "<<it->second<<endl;
        table[it->second]++;
    }*/

    for(j=0;j<len;j++)
    {
        string temp="";

        for(k=j;k<len;k++)
        {
            temp.push_back(str[k]);

            if(memo[temp]!=0)
            {
                table[memo[temp]]++;
                memo[temp]=0;
            }
        }
    }

}

void solve1()
{
    long long i,j,k;
    long long sum=0;

    for(j=1;j<=len;j++)
    {
        sum=0;
        for(i=j;i<=len;i++)
        {
            sum=(sum+table[i]*ncr[i][j])%M;
        }
        ans[j]=sum;
    }
}

int main()
{
    long long test,i,j,k;
    long long ans1;

    calc();

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        if(i!=0)
            memo.clear();

        //memset(table,0,sizeof(table));

        scanf("%lld%lld",&n,&q);

        cin>>str;
       // len=str.length();
       len=n;

       for(j=0;j<=n;j++)
        table[j]=0;

        for(j=0;j<len;j++)
        {
            string temp="";

            for(k=j;k<len;k++)
            {
                temp.push_back(str[k]);
                memo[temp]++;
            }
        }

        solve();
        solve1();

        for(j=0;j<q;j++)
        {
            scanf("%lld",&K);

            if(K>len)
            {
                printf("0\n");
                continue;
            }

            ans1=ans[K];

            printf("%lld\n",ans1);
        }

    }

    return 0;
}
