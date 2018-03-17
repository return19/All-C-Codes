#include<bits/stdc++.h>
using namespace std;

char str[101000];
long long n;
long long M = 1e9 + 7;
long long memo[101000][2][2];

long long solve(long long idx,long long t1,long long t2){
    if(idx == n){
        if(t1 == 1 && t2 == 1)
            return 1;
        return 0;
    }

    if(memo[idx][t1][t2] != -1)
        return memo[idx][t1][t2];

    long long i,j,k;
    long long ans=0;

    if(t1 == 1){
        for(i=0;i<26;i++){
            if(str[idx]-'A'==i){
                ans =  (ans + solve(idx+1,t1,t2))%M;
            } else if(i < str[idx]-'A'){
                ans = (ans + solve(idx+1,t1,0))%M;
            } else {
                ans = (ans + solve(idx+1,t1,1))%M;
            }
        }
    } else {
        ans = (ans + solve(idx+1,t1,t2))%M;
        for(i=str[idx]-'A'+1;i<26;i++){
            ans = (ans + solve(idx+1,1,1))%M;
        }
    }

    return memo[idx][t1][t2] = ans;
}

int main(){
    long long i,j,k;
    scanf("%s",str);
    n = strlen(str);

    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                memo[i][j][k]=-1;

    long long ans = solve(0,0,0);

    printf("%lld\n",ans);

    return 0;
}
