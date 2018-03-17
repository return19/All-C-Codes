#include<bits/stdc++.h>
using namespace std;

int n;

int arr[2010][2010];

int vis[2010];

int arr2[2010][2010];

vector< pair< pair<int,int>,int > > e;

vector< vector< pair<int,int> > > adj(2010);

int par[2010];

int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int cmp(pair< pair<int,int>,int > a,pair< pair<int,int>,int > b)
{
    return a.second<b.second;
}

void dfs(int o,int x,int d,int p)
{
    int i;
    vis[x]=1;

    arr2[o][x]=d;

    for(i=0;i<adj[x].size();i++)
    {
        if(adj[x][i].first==p)
            continue;
        if(!vis[adj[x][i].first])
            dfs(o,adj[x][i].first,d+ adj[x][i].second ,x);
    }
}

int validate()
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i][j]!=arr[j][i])
                return 0;

            if(i!=j && arr[i][j]==0)
                return 0;

        }
    }

    for(i=0;i<n;i++)
        if(arr[i][i]!=0)
            return 0;
    return 1;
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        par[i]=-1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);

            if(i!=j)
                e.push_back(make_pair(make_pair(i,j),arr[i][j]));
        }
    }

    int temp=validate();

    if(temp==0)
    {
        printf("NO\n");
        return 0;
    }

    sort(e.begin(),e.end(),cmp);

    for(i=0;i<e.size();i++)
    {
        int x=e[i].first.first;
        int y=e[i].first.second;
        int d=e[i].second;

        if(root(x)!=root(y))
        {
            merge_dsu(x,y);

            adj[x].push_back(make_pair(y,d));
            adj[y].push_back(make_pair(x,d));
        }
    }

    for(i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));

        dfs(i,i,0,-1);
    }
/*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr2[i][j]<<" ";
        cout<<endl;
    }

    cout<<"here"<<endl;*/

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(arr[i][j]!=arr2[i][j])
            {
                printf("NO\n");
                return 0;
            }

    printf("YES\n");

    return 0;
}




