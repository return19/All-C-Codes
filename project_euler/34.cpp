#include<bits/stdc++.h>
using namespace std;

int fact[10];

int main()
{
    int i,j,k;
    int n;
    fact[0]=1;
    for(i=1;i<=9;i++)
        fact[i] = fact[i-1]*i;
    scanf("%d",&n);
    int ans=0;
    for(i=10;i<=n;i++){
        int temp = i;
        int mod = 0;
        while(temp){
            mod = (mod + fact[temp%10])%i;
            temp/=10;
        }
        if(mod==0)
            ans = ans + i;
    }
    printf("%d\n",ans);

    return 0;
}
