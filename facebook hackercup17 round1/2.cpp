#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
long long graph[110][110];
long long s[5100];
long long d[5100];
long long dp[5100][110];

long long solve(long long i,long long pos){
    if(i==k)
        return 0;
    if(i==k-1)
        return graph[pos][d[i]];

    if(dp[i][pos]!=-1)
        return dp[i][pos];

    long long one,two;
    long long ans_one=solve(i+1,s[i+1]);
    long long ans_two=solve(i+1,d[i]);

    if(graph[ pos ][ d[i] ] == LLONG_MAX ||
       graph[ d[i] ][ s[i+1] ] == LLONG_MAX)
        one=LLONG_MAX;
    else
        one = graph[ pos ][ d[i] ] + graph[ d[i] ][ s[i+1] ];

    if(graph[ pos ][ s[i+1] ]==LLONG_MAX ||
        graph[ s[i+1] ][ d[i] ]==LLONG_MAX)
        two = LLONG_MAX;
    else
        two = graph[ pos ][ s[i+1] ] + graph[ s[i+1] ][ d[i] ];

    if(one ==LLONG_MAX || ans_one==LLONG_MAX)
        ans_one = LLONG_MAX;
    else
        ans_one += one;

    if(two == LLONG_MAX || ans_two==LLONG_MAX)
        ans_two=LLONG_MAX;
    else
        ans_two += two;

    return dp[i][pos] = min(ans_one,ans_two);
}

int main()
{
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    long long i,j;
    long long x,y,z;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld%lld%lld",&n,&m,&k);

        for(i=0;i<=k;i++)
            for(j=0;j<=n;j++)
                dp[i][j]=-1;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)
                    graph[i][j]=0;
                else
                    graph[i][j]=LLONG_MAX;
            }
        }

        for(i=0;i<m;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;    y--;
            graph[x][y] = min(graph[x][y],z);
            graph[y][x] = min(graph[y][x],z);
        }

        for(x=0;x<n;x++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(graph[i][x]!=LLONG_MAX &&
                       graph[x][j]!=LLONG_MAX &&
                    graph[i][x]+graph[x][j] < graph[i][j]){
                        graph[i][j] = graph[i][x] + graph[x][j];
                    }

                }
            }
        }

        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }*/

        for(i=0;i<k;i++){
            scanf("%lld%lld",&s[i],&d[i]);
            s[i]--;
            d[i]--;
        }

        long long ans=graph[0][s[0]];
        long long ans2 = solve(0,s[0]);
        if(ans==LLONG_MAX || ans2==LLONG_MAX)
            printf("Case #%lld: -1\n",t+1);
        else
            printf("Case #%lld: %lld\n",t+1,ans+ans2);
    }

    return 0;
}
