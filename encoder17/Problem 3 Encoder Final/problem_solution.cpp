#include<bits/stdc++.h>
using namespace std;
#define M (int)1e2
typedef long long ll;
int input()
{
    int t=0;
    char ch=getchar();
    while(ch<33)
    ch=getchar();
    while(ch>33)
    {
        t=(t<<3)+(t<<1)+ch-'0';
        ch=getchar();
    }
    return t;
}
int row[]={-1,1,0,0};
int col[]={0,0,1,-1};
int n,m,cnt;
char a[M][M],b[M][M];
void dfs(int i,int j)
{
	if(i<0||i>=n||j<0||j>=m) return;
	if(a[i][j]=='#'||b[i][j]) return;
	cnt++;b[i][j]=1;
	for(int k=0;k<4;k++)
	{
		dfs(i+row[k],j+col[k]);
	}
}
int main()
{
   // freopen("samplein01.txt","r",stdin);
    //freopen("sampleout01.txt","w",stdout);
	int i,j;
	int rate_emp,new_emp,rate_boss,new_boss;
	ll ans;
	char ch;
	n=input();m=input();
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	rate_emp=input();new_emp=input();
	rate_boss=input();new_boss=input();
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='B')
			{
				cnt=0;
				dfs(i,j);
				break;
			}
		}
	}
	ans=rate_boss*cnt+new_boss;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!='#'&&!b[i][j])
			{
				cnt=0;
				dfs(i,j);
				ans+=rate_emp*cnt+new_emp;
			}
		}
	}
	printf("The total cost is %lld.",ans);
}
