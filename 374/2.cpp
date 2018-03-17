#include<bits/stdc++.h>
using namespace std;

long long l[110];
long long act;
char s[110];

int main()
{
    long long i,j,k;
    long long n;
    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++){
        scanf("%s",s);
        long long x = strlen(s);
        l[x]++;
    }
    scanf("%s",s);
    act = strlen(s);

    for(i=2;i<act;i++)
        l[i]+=l[i-1];

    long long ans = 0;
    if(act>1)
        ans = ans + l[act-1] + (l[act-1]/k)*5;
    printf("%lld %lld\n",ans+1,ans + l[act]-1 + ((l[act]-1)/k)*5 + 1);

    return 0;
}
