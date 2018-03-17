#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int mcm(int n)
{

    int dp[n][n];

    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        dp[i][i] = 0;

    for (L=2; L<n; L++)
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            dp[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {

                q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    return dp[1][n-1];
}


int main()
{
    int i,j,k;

    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Minimum required multiplications %d\n",mcm(n));


    return 0;
}
