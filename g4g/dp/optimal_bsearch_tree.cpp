#include<bits/stdc++.h>
using namespace std;

int keys[1100];
int freq[1100];

int pro[1100];

int dp[1100][1100];

void cal(int n)
{
    int i;
    pro[1]=freq[0];

    for(i=2;i<=n;i++)
    {
        pro[i]=pro[i-1]+freq[i-1];
    }
}

int cal_sum(int i,int j)
{
    if(i>j)
        return 0;

    return pro[j+1]-pro[i];
}

int optimal_binary_tree(int n)
{
    int i,j,k;

    int temp;
    int min_sum=INT_MAX;

    for(int gap=1;gap<=n;gap++)
    {
        for(i=0;i<n-gap+1;i++)
        {
            j=i+gap-1;

            min_sum=INT_MAX;

            for(k=i;k<=j;k++)
            {
                temp=dp[i][k-1]+dp[k+1][j];

                if(temp<min_sum)
                    min_sum=temp;
            }

            dp[i][j]=cal_sum(i,j)+min_sum;
        }
    }

    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return dp[0][n-1];
}

int main()
{
    int i,j,k;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&keys[i]);
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&freq[i]);
    }

    cal(n);

    int ans=optimal_binary_tree(n);

    printf("%d",ans);

    return 0;
}
