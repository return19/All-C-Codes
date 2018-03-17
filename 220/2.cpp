#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long arr[101000];
pair<long long,long long> memo[101000];
char s[101000];
long long n;

pair<long long,long long> solve(long long idx){
    if(idx>=n-1)
    {
        return mp(0,1);
    }

    if(memo[idx].ft!=-1)
        return memo[idx];

    if(idx+1<n && arr[idx] + arr[idx+1]==9)
    {
        pair<long long,long long> tk,nt;
        tk= solve(idx+2);
        tk.ft++;

        nt=solve(idx+1);

        if(tk.ft==nt.ft)
            return memo[idx]=mp(tk.ft,tk.sd + nt.sd);
        else if(tk.ft>nt.ft){
            return memo[idx]=tk;
        }else
            return memo[idx]=nt;
    }

    return memo[idx]=solve(idx+1);
}

int main()
{
    long long i,j,k;
    scanf("%s",s);

    n=strlen(s);

    for(i=0;i<n;i++){
        memo[i].ft=-1;
        memo[i].sd=-1;
    }

    for(i=0;i<n;i++)
        arr[i]=s[i]-'0';

    pair<long long,long long> ans=solve(0);

    printf("%lld\n",ans.sd);
    return 0;
}
