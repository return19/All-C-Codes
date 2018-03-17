#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[101000];

typedef struct a
{
    int i;
    int len;
}elem;

elem ship[101000];

int csum[101000];

int cmp(elem a,elem b)
{
    return a.i<b.i;
}

inline int getsum(int l,int r)
{
    return csum[r]-csum[l]+arr[l];
}

vector< vector<int> > memo;

int solve(int idx,int x)
{
    if(x==m)
        return 0;
    if(idx>=n)
        return INT_MIN;



    int i,j,k;

    if(memo[idx][x]!=-1)
        return memo[idx][x];

    int ans=INT_MIN;

    for(i=max(idx,ship[x].i-ship[x].len+1) ;i+ship[x].len-1<n && i<n && i<=ship[x].i;i++)
    {
        ans=max(ans, getsum(i,i+ship[x].len-1) + solve(i+ship[x].len,x+1));
      //  cout<<i<<" "<<i+ship[x].len-1<<"  : ";
        //cout<<getsum(i,i+ship[x].len-1)<<" "<<endl;
    }

    //cout<<idx<<" "<<x<<" "<<ans<<endl;

    return memo[idx][x]=ans;
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        if(i==0)
            csum[i]=arr[i];
        else
            csum[i]=arr[i] + csum[i-1];
    }

    scanf("%d",&m);

    memo.resize(n);

    for(i=0;i<n;i++)
    {
        memo[i].resize(m);

        for(j=0;j<m;j++)
            memo[i][j]=-1;
    }

    for(i=0;i<m;i++){
        scanf("%d%d",&ship[i].i,&ship[i].len);
        ship[i].i --;
    }

    sort(ship,ship + m ,cmp);

    int ans=solve(0,0);

    printf("%d\n",ans);

    return 0;
}







