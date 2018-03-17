#include<bits/stdc++.h>
using namespace std;

int n,m;
int k,w;

int tk[1010];

vector<int> fin;

vector< vector<int> > v[1010];

vector< pair< pair<int,int>,int > > e;

vector< vector< pair<int,int> > > adj(1010);

int vis[1010];

int prev1[1010];

int par[1010];

void dfs(int x,int p,int z)
{
    vis[x]=1;
    prev1[x]=p;

    if(z<n*m)
        printf("%d %d\n",x+1,p);
    else
        printf("%d 0\n",x+1);

    int i;

    for(i=0;i<adj[x].size();i++)
        if(!vis[adj[x][i].first])
            dfs(adj[x][i].first,x+1,adj[x][i].second);
}

int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int cmp(pair< pair<int,int>,int> x,pair< pair<int,int>,int> y)
{
    return x.second < y.second;
}

int find_diff(vector< vector<int> > a,vector< vector<int> > b)
{
    int i,j,k;
    int ans=0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(a[i][j]!=b[i][j])
                ans++;
    return ans;
}

char str[21];

int main()
{
    int i,j;
    int x,y,z;
    int t;

    scanf("%d%d%d%d",&n,&m,&k,&w);

    for(i=0;i<k;i++){
        par[i]=-1;
        prev1[i]=-1;
        vis[i]=0;
    }

    for(i=0;i<k;i++)
    {
        tk[i]=1;
        v[i].resize(n);

        for(x=0;x<n;x++)
        {
            scanf("%s",str);

            for(y=0;y<m;y++)
            {
                if(str[y]=='.')
                    t=0;
                else
                    t=1+str[y]-'A';
                v[i][x].push_back(t);
            }
        }
    }

    for(i=0;i<k;i++)
        for(j=i+1;j<k;j++)
            if(tk[j])
            {
                t=find_diff(v[i],v[j]);

                if(t==0){
                    tk[j]=0;
                    prev1[j]=i+1;
                }
            }

    for(i=0;i<k;i++)
        if(tk[i])
            fin.push_back(i);

    //cout<<" here "<<fin.size()<<endl;

    int maxi=0;

    for(i=0;i<fin.size();i++)
    {
        for(j=0;j<fin.size();j++)
        {
            if(i!=j)
            {
                t=find_diff(v[fin[i]],v[fin[j]]);
                e.push_back(make_pair(make_pair(fin[i],fin[j]),t));
                //cout<<e.first.first<<" "<<e.first.second<<""
                maxi++;
            }
        }
    }

    sort(e.begin(),e.end(),cmp);

    int ans=n*m;


    //prev1[]=0;

    for(i=0;i<maxi;i++)
    {
        x=e[i].first.first;
        y=e[i].first.second;
        z=e[i].second;

        if(root(x)!=root(y))
        {
            //cout<<" :: "<<x<<" "<<y<<endl;

            adj[x].push_back(make_pair(y,z*w));
            adj[y].push_back(make_pair(x,z*w));

            ans+=min(n*m,z*w);
            merge_dsu(x,y);
        }
    }



    printf("%d\n",ans);
    dfs(e[0].first.first,0,INT_MAX);
    for(i=0;i<k;i++)
    {
        if(!tk[i])
            printf("%d %d\n",i+1,prev1[i]);
    }

    return 0;
}






















