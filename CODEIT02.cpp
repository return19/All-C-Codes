#include<bits/stdc++.h>
using namespace std;

int arr[21];
int n,k;
int ans;

void solve(int idx,int tk,int res){
    if(idx == n){
        if(tk==0)
            ans = max(ans,res);
        return;
    }

    solve(idx+1,tk,res);
    if(tk)
        solve(idx+1,tk-1,res^arr[idx]);
}

int main()
{
    int i,j;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        ans = 0;
        solve(0,k,0);
        printf("%d\n",ans);
    }

    return 0;
}
