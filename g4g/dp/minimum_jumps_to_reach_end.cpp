#include<bits/stdc++.h>
using namespace std;

int arr[100100];
int dp[100100];
int bck[100100];
int n;


int solve_dp()
{
    int i,j,k;

    for(i=0;i<n;i++)
        dp[i]=INT_MAX;

    dp[0]=0;
    bck[0]=-1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(dp[j]!=INT_MAX&&arr[j]+j>=i)
            {
                dp[i]=min(dp[i],dp[j]+1);

                if(dp[i]==dp[j]+1)
                {
                    bck[i]=j;
                }
            }
        }
    }

    return dp[n-1];
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int ans=solve_dp();

    if(ans!=INT_MAX){
        printf("%d\n",ans);

        i=n-1;

        while(i!=-1)
        {
            cout<<arr[i]<<" <--";

            i=bck[i];
        }

        cout<<endl;
    }
    else
        printf("Not Possible\n");

    return 0;
}
