#include<bits/stdc++.h>
using namespace std;

char str1[1010];
char str2[1010];
int n,m;
int dp[1010][1010];

int lcs()
{

    int ans = 0;
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}


int main()
{
    int i,j,k;

    scanf("%s",str1);
    scanf("%s",str2);

    m=strlen(str1);
    n=strlen(str2);

    printf("lcs is : %d",lcs());
    return 0;
}
