#include<bits/stdc++.h>
using namespace std;
// C
map<long long,long long> memo;
char str[101000];
long long M= 1e9 +7;

int main()
{
    long long i,j,k;

    for(i=0;i<64;i++){
        for(j=0;j<64;j++){
            memo[i&j]++;
        }
    }

    //cout<<memo[63]<<endl;

    scanf("%s",str);
    long long n=strlen(str);

    long long ans=1;

    for(i=0;i<n;i++){
        if('0'<=str[i] && str[i]<='9'){
            ans = (ans*memo[str[i]-'0'])%M;
        }else if('A'<=str[i] && str[i]<='Z'){
            ans = (ans*memo[str[i]-'A' + 10])%M;
        }else if('a'<=str[i] && str[i]<='z'){
            ans = (ans*memo[str[i]-'a' + 36])%M;
        }else if(str[i]=='-'){
            ans = (ans*memo[62])%M;
        }else{
            ans = (ans*memo[63])%M;
        }
    }

    printf("%lld\n",ans);


    return 0;
}

