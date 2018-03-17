#include<bits/stdc++.h>
using namespace std;

int longestps(char str[])
{
   int n = strlen(str);
   int i, j, gap;

   int dp[n][n];

   for (i = 0; i < n; i++)
      dp[i][i] = 1;

    for (gap=2; gap<=n; gap++)
    {
        for (i=0; i<n-gap+1; i++)
        {
            j = i+gap-1;
            if (str[i] == str[j] && gap == 2)
               dp[i][j] = 2;
            else if (str[i] == str[j])
               dp[i][j] = dp[i+1][j-1] + 2;
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }

    return dp[0][n-1];
}

char str[10100];

int main()
{
    int i,j,k;

    scanf("%s",str);

    printf("Required length of lps : %d\n",longestps(str));

    return 0;
}
