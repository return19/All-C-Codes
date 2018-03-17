#include<bits/stdc++.h>
using namespace std;

int dp[1000010];
int nums[10010];
int sum,k=-1;

/*inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}
*/
void init()
{
    int i,j,total=0;
    dp[0]=1;

    for(i=0;i<=k;k++)
    {
        total=total+nums[k];
        for(j=total;j<=sum;j++)
        {
            dp[j]=dp[j]||dp[j-total];
        }
    }
}

int main()
{
    int i,j;

    scanf("%d",&sum);
    while(scanf("%d",&nums[++k]))
    {

    }


    init();

    if(dp[sum])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}





















