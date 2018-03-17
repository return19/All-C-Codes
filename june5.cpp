#include<bits/stdc++.h>

using namespace std;

//string a,b;
unordered_map<string,long long> memo;
unordered_map<string,long long>::iterator it;
long long MOD = 1e9 + 7;
long long C[5110][5110];
char x[5010];
long long num[5010];
long long ans[5010];
int main()
{
    long long t,n,q,k;

    scanf("%lld",&t);


    for(long long i=0;i<5100;i++)
        C[i][0] = 1;

    for(long long i = 1;i<5100;i++)
        for(long long j=1;j<=i;j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
    /*
    for(long long i=0;i<10;i++){
        for(long long j=0;j<=i;j++)
            prlong longf("%lld ",C[i][j]);

        prlong longf("\n");
    }
    */
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        //cin>>a;for(map<char*,long long>::iterator it = memo.begin();it!=memo.end();it++){
               // cout<<it->first<<" "<<it->second<<endl;
        scanf("%s",x);

       // cin>>a;

        memo.clear();

        for(long long i=0;i<=n;i++){
            num[i] = 0;
            ans[i] = 0;
        }

        for(long long i = 0;i<n;i++)
        {
            string a;
            for(long long j=0;j<n-i;j++)
            {
                a.push_back(x[i+j]);
                memo[a]++;
            }
        }

       // for(map<string,long long>::iterator it = memo.begin();it!=memo.end();it++)
           //    cout<<it->first<<" "<<it->second<<endl;


        for(long long i = 0;i<n;i++)
        {
            string a;
            for(long long j=0;j<n-i;j++)
            {
                a.push_back(x[i+j]);

                if(memo[a]!==0){
                    num[memo[a]]++;
                    memo[a] = 0;
                }
            }
        }
        //for(it = memo.begin();it!=memo.end();it++)
          //  num[it->second]++;

        for(long long i=1;i<=n;i++){
            long long val = 0;
            for(long long j=i;j<=n;j++)
                val = (val + (num[j]*C[j][i])%MOD)%MOD;

            ans[i] = val;
        }



        for(long long i=0;i<q;i++){
            scanf("%lld",&k);
            if(k<=n)
                printf("%lld\n",ans[k]);
            else
                printf("0\n");
        }
    }
}

