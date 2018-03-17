#include<bits/stdc++.h>
using namespace std;

int arr[5010];

char a[5110];
int s;

int n;

int memo[5010][5010];
int vis[5010][5010];

int solve(int idx,int sum)
{

    if(idx==n)
    {
        if(sum==0)
            return 0;
        return 999999;
    }

    if(vis[idx][sum]==1)
        return memo[idx][sum];

    vis[idx][sum]=1;

    int i,j,k;

    int c=0;
    int mn=999999;

    for(i=idx;i<n;i++)
    {
        c=c*10 + arr[i];

        if(c==sum&&i==n-1)
            return 0;

        if(c>sum)
            break;

        mn=min(mn,1+solve(i+1,sum-c));
    }

    //cout<<idx<<" "<<sum<<" : "<<mn<<endl;

    return memo[idx][sum]=mn;

}


int main()
{
    int i;
    int t;

    scanf("%s",a);

    n=strlen(a);

    s=0;

    i=0;

    while(i<n&&a[i]=='0')
        i++;

    int st=i;

    int k=-1;

    for(;i<n;i++){
        if(a[i]!='='){
            arr[++k]=a[i] - '0';
            t=i-st+1;
        }
        else
        {

            i++;
            while(i<n){
                s=s*10 + a[i]-'0';
                i++;
            }
        }
    }

        n=t;

       /* for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        cout<<s<<endl;*/



	int ans=solve(0,s);

	printf("%d\n",ans);

	return 0;
}
