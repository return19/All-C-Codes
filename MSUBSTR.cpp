#include<bits/stdc++.h>
using namespace std;

int n,maxl=0,count1=0;
char str[3010];
int dp[3010][3010];

void init_dp()
{
    maxl=0;
    count1=0;
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n-k;i++)
        {
            j=i+k;
            if(i==j){
                dp[i][j]=1;
            }
            else if(j-i==1)
            {
                if(str[i]==str[j])
                {
                    dp[i][j]=2;
                }
                else
                {
                    dp[i][j]=1;
                }
            }
            else
            {
                if(str[i]==str[j])
                {
                    if(dp[i+1][j-1]==(j-1-(i+1)+1))
                    {
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j]=dp[i+1][j-1];
                }
            }
            if(maxl<dp[i][j])
            {
                maxl=dp[i][j];
                count1=1;
            }
            else if(maxl==dp[i][j]&&(dp[i][j]==(j-i+1)))
            {
                count1++;
                //cout<<i<<" "<<j<<"  value of k : "<<k<<endl;
            }
        }
    }
}

int main()
{
    int test,i,j,k;
    scanf("%d",&test);
    for(i=0;i<test;i++){
        scanf("%s",str);
        n=strlen(str);
        init_dp();
        /*for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                cout<<dp[j][k]<<" ";
            cout<<endl;
        }*/

        printf("%d %d\n",maxl,count1);
    }
    return 0;
}
