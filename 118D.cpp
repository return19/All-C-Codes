#include<bits/stdc++.h>
using namespace std;

long long n1,n2,k1,k2;
long long memo[220][110][2];
long long M = 1e8;

long long solve(long long idx,long long cur,long long t){
    long long i,j,k;

    //cout<<idx<<" "<<cur<<" "<<t<<endl;
    if(idx == n1 + n2)
        return 1;

    if(memo[idx][cur][t]!=-1)
        return memo[idx][cur][t];

    long long ans=0;

    if(t==0){
        for(i=1; i <= n1 - (idx-cur) && i<=k1 && idx+i <= n1+n2 ;i++ ){
            ans = (ans + solve(idx+i,cur,1-t))%M;
        }
    } else {
        for(i=1 ; i <= n2-cur && i<=k2 && idx + i <= n1+n2 ;i++){
            ans = ( ans + solve(idx+i,cur+i,1-t))%M;
        }
    }
    return memo[idx][cur][t] = ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld%lld%lld",&n1,&n2,&k1,&k2);

    for(i=0;i<=n1+n2;i++)
        for(j=0;j<=n2;j++)
        {
            memo[i][j][0]=-1;
            memo[i][j][1]=-1;
        }

    long long ans = solve(0,0,0) + solve(0,0,1);

    printf("%lld\n",ans%M);

    return 0;
}
