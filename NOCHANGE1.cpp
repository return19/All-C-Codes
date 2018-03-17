#include<bits/stdc++.h>
using namespace std;

long long arr[10];
long long csum[10];

long long dp[110000];

int main()
{
    long long n,k,i,j,p;

    scanf("%lld%lld",&n,&k);

    csum[0]=0;

    for(i=1;i<=k;i++)
    {
        scanf("%lld",&arr[i]);
        csum[i]=csum[i-1]+arr[i];
    }

    dp[0]=1;



    for(i=1;i<=n;i++)
        dp[i]=0;

    for(i=1;arr[1]*i<=n;i++)
        dp[i*arr[1]]=1;


    for(i=2;i<=k;i++)
    {
        //cout<<"here1"<<endl;
        for(j=0;j*csum[i-1]+arr[i]<=n;j++)
        {
            //cout<<"here2"<<endl;
            for(p=0;p<=j&&(j*csum[i-1]+p*arr[i]<=n);p++){
                dp[j*csum[i-1]+p*arr[i]]=1;
               // cout<<csum[i-1]<<" "<<j*csum[i-1]<<" "<<arr[i]<<" "<<p*arr[i]<<endl;
            }
        }
    }

    for(i=1;i*csum[k]<=n;i++)
        dp[i*csum[k]]=1;

    /*for(i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/

    if(dp[n])
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
