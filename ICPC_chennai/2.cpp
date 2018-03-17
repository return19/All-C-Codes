#include<bits/stdc++.h>
using namespace std;

long long a[2000];
long long dp[1500][1500];

void build()
{
    dp[1][1] = 1;
    for(int i=2;i<1100;i++){
        for(int j=1;j<=i;j++)
            dp[i][j] = dp[i-1][j-1] + j*dp[i-1][j];
    }
}

int main()
{
    int t,n;

    cin>>t;

    build();
    /*
    for(int i=1;i<10;i++)
        for(int j=1;j<=i;j++)
            cout<<dp[i][j];
        cout<<endl;
    */

    while(t--){

        int c=0;
        double ans = 0;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==-1)
                c++;
        }

        double x=0;
        for(int i=1;i<=c;i++){
            ans+=(dp[c][i]*i);
            x+=dp[c][i];
        }

        /*cout<<pow2(2,4);
        cout<<pow2(2,6);
        cout<<pow2(2,10);
        */

        ans/=x;

        printf("%.6lf\n",ans);
    }

}
