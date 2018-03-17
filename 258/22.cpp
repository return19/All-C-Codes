/********************

	root8950

*********************/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define ft first
#define sd second
#define MAXN MOD
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
#define pb push_back
#define MOD 1000000007
#define PIE 3.141592653589
#define inf INT_MAX/2
#define ASST(X,L,R) assert(X >= L && X <= R)

int arr[110000];
int sort_arr[110000];


int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	t=1;
	int i,j,k;

	while(t--){
		int n;

		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sort_arr[i]=arr[i];
		}

		sort(sort_arr,sort_arr+n);

		int f1,f2;

		f1=0;
		f2=0;

		for(i=0;i<n;i++)
			if(sort_arr[i]!=arr[i]){
				f1=i;
				break;
			}


		for(i=n-1;i>=0;i--)
		{
				if(sort_arr[i]!=arr[i])
				{f2=i;
				break;
				}
		}

		for(i=f1,j=f2;i<=j;i++,j--)
		{
			if(sort_arr[i]!=arr[j] || sort_arr[j]!=arr[i])
			{
				printf("no\n");
				return 0;
			}

		}

		printf("yes\n");
		printf("%d %d",f1+1,f2+1);

	}
	return 0;
}
