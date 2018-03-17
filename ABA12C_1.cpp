#include<bits/stdc++.h>
        using namespace std;

        long long int n,a[105],k;
        long long int dp[110][110];
        long long int fun(int i,int packet,int sum)
        {
            if(sum<0)
                return 999999; // correct
            //if(packet<=0 && sum!=0) // not correct
              //  return INT_MAX;
              // conditions should be as follows :
            if(packet<0)
                return 999999;
            if(packet==0 && sum!=0)
                return 999999;
            if(packet==0 && sum==0)
                return 0;

            if(i>k)
            {
                if(sum==0)
                    return 0;
                else
                    return 999999;
            }
            //if(sum==0 && packet>=0 && i<=k+1)
              //  return 0; no need of condition
            if(dp[i][sum]!=-1)
             return dp[i][sum]; // correct
            //if(a[i]==-1)
            //{
              //  dp[i][packet]=fun(i+1,packet,sum); // check this for every case
            //}
            dp[i][sum]=fun(i+1,packet,sum);

            if(a[i]!=-1){
            dp[i][sum]=min(fun(i,packet-1,sum-i)+a[i],dp[i][sum]);

            }
            return dp[i][sum];
        }


        int main()
        {
            int t;
            cin>>t;
            while(t--)
            {
               cin>>n>>k;
               for(int i=1;i<=k;i++)
               scanf("%d",&a[i]);
               memset(dp,-1,sizeof(dp));


               long long int z=fun(1,n,k);
               if(z==999999)
               printf("-1\n");
               else
               printf("%lld\n",z);

            }
        }
/*#include<bits/stdc++.h>
using namespace std;

#define MAX 999999999

long long n,k;
long long arr[110];

long long memo[110][110][110];

long long solve(long long idx,long long cur_app,long long cur_w){
    long long i,j;

    if(cur_app>n)
        return MAX;

    if(cur_w>k)
        return MAX;

    if(idx==k){
        if(cur_w==k)
            return 0;
        return MAX;
    }

    if(memo[idx][cur_app][cur_w]!=-1)
        return memo[idx][cur_app][cur_w];

    long long tk=MAX,nt=MAX;

    if(arr[idx]!=-1){
        j=1;
        while(cur_app+j<=n && cur_w + (idx+1)*j <=k){
            tk=min(tk,arr[idx]*j + solve(idx+1,cur_app+j,cur_w+(idx+1)*j));
            j++;
        }
    }
    nt=solve(idx+1,cur_app,cur_w);

    return memo[idx][cur_app][cur_w]=min(tk,nt);

}


int main()
{
    long long i,j;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld%lld",&n,&k);

        for(i=0;i<k;i++){
            scanf("%lld",&arr[i]);
        }

        for(i=0;i<=k;i++)
            for(j=0;j<=n;j++)
                for(long long x=0;x<=k;x++)
                    memo[i][j][x]=-1;

        long long ans=solve(0,0,0);
        if(ans>=MAX)
            printf("-1\n");
        else
            printf("%lld\n",ans);
    }

    return 0;
}
*/
