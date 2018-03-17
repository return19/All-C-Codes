#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[201000];

int par[201000];

int vis[201000];
int sz[201000];
int ans[201000];

int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
	sz[x]=sz[x]+sz[y];
}


int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        par[i]=-1;
        sz[i]=1;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i].first);
        arr[i].second=i;
    }

    sort(arr,arr+n,greater< pair<int,int> >());

    int cur=1;

    for(i=0;i<n;i++)
    {
        int val=arr[i].first;
        int pos=arr[i].second;

        vis[pos]=1;

        if(pos>0 && vis[pos-1]==1)
            merge_dsu(pos,pos-1);
        if(pos<n-1 && vis[pos+1]==1)
            merge_dsu(pos,pos+1);

        int sz1=sz[root(pos)];

        while(cur<=sz1)
            ans[cur++]=val;
    }

    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);

    return 0;
}










