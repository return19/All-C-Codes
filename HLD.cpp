#include<bits/stdc++.h>
using namespace std;
#define N 101000
#define LN 18

class st
{
    int s[401000];
    int lazy[401000];
    int f[401000];
    int n;

    void shift(int idx,int l,int r)
    {
        int mid=l + (r-l)/2;

        if(f[idx]==1){
            update((idx<<1)+1,l,mid,lazy[idx]);
            update((idx<<1)+2,mid+1,r,lazy[idx]);
        }
        lazy[idx]=0;
        f[idx]=0;
    }

    void update(int idx,int l,int r,int val)
    {
        lazy[idx]=val;
        s[idx]=val;
        f[idx]=1;
    }

    void build(int idx,int l,int r,int arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            return;
        }

        int mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=max(s[(idx<<1)+1],s[(idx<<1)+2]);
    }

    void increase(int idx,int l,int r,int ql,int qr,int val)
    {
        if(ql>r || qr<l)
            return;

        if(ql<=l&&r<=qr)
        {
            update(idx,l,r,val);
            return;
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        increase((idx<<1)+1,l,mid,ql,qr,val);
        increase((idx<<1)+2,mid+1,r,ql,qr,val);

        s[idx]=max(s[(idx<<1)+1],s[(idx<<1)+2]);
    }

    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>r || qr<l)
            return 0;

        if(ql<=l&&r<=qr)
        {
            return s[idx];
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        return max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
    }

public:

    st()
    {}

    st(int n)
    {
        int i;
        (*this).n=n;

        for(i=0;i<=n*4;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void setN(int n)
    {
        (*this).n=n;

        for(int i=0;i<=4*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void build(int arr[])
    {
        build(0,0,n-1,arr);
    }

    void increase(int l,int r,int val)
    {
        increase(0,0,n-1,l,r,val);
    }

    int query(int l,int r)
    {
        return query(0,0,n-1,l,r);
    }


};

st one(1);

int pa[LN][N],depth[N],chainHead[N],posInBase[N],baseArray[N],chainIdx[N],otherEnd[N];
vector<int> adj[N];
vector<int> cost[N],indexx[N];
int subSize[N];
int n;
int chainNo,ptr;

void HLD(int cur,int cost1,int prev)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=cur;
    chainIdx[cur]=chainNo;
    posInBase[cur]=ptr;
    baseArray[ptr]=cost1;
    ptr++;
    int sc=-1,scost;
    int i,j,k;

    for(i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]==prev)
            continue;

        if(subSize[adj[cur][i]]>sc)
        {
            sc=adj[cur][i];
            scost=cost[cur][i];
        }
    }

    if(sc!=-1)
        HLD(sc,scost,cur);

    for(i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]==prev)
            continue;
        if(adj[cur][i]!=sc)
        {
            chainNo++;
            HLD(adj[cur][i],cost[cur][i],cur);
        }
    }

}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void dfs(int x,int par,int d)
{
    //cout<<x<<endl;
    int i,j,k;
    if(par!=-1)
        pa[0][x]=par;
    depth[x]=d;
    subSize[x]=1;
    for(i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==par)
            continue;
        dfs(adj[x][i],x,d+1);
        otherEnd[indexx[x][i]]=adj[x][i];
        subSize[x]+=subSize[adj[x][i]];
    }
}

int query_up(int u,int v)
{
    int uchain,vchain;

    if(u==v)    return 0;
    int ans=INT_MIN;
    vchain=chainHead[v];

    while(1)
    {
        uchain=chainHead[u];

        if(uchain==vchain)
        {
            if(u==v)
                break;
            ans=max(ans,one.query(posInBase[u],posInBase[v]));
            return ans;
        }

        ans=max(ans,one.query(posInBase[chainHead[u]],posInBase[u]));
        u=chainHead[u];
        u=pa[0][u];
    }
    return ans;

}

int query(int u,int v)
{
    int lca=LCA(u,v);

    int ans=max(query_up(u,lca),query_up(v,lca));
    printf("%d\n",ans);
}

void change(int u,int val)
{
    u=otherEnd[u];
    one.increase(u,u,val);
}

int main()
{
    int i,j,k;
    int test,t;
    int x,y,z;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            adj[i].clear();
            cost[i].clear();
            indexx[i].clear();
            chainHead[i]=-1;

            for(j=0;j<LN;j++)   pa[j][i]=-1;
        }

        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;    y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
            indexx[x].push_back(i);
            indexx[y].push_back(i);
        }

       // cout<<"start"<<endl;
        dfs(0,-1,0);
       // cout<<"here"<<endl;
        chainNo=0;
        ptr=0;
        HLD(0,-1,-1);
       // cout<<"here2"<<endl;

        one.setN(n+10);
        one.build(baseArray);
       // cout<<"here3"<<endl;
        // Below Dynamic programming code is for LCA.
            for(int i=1; i<LN; i++)
                for(int j=0; j<n; j++)
                    if(pa[i-1][j] != -1)
                        pa[i][j] = pa[i-1][pa[i-1][j]];

       // cout<<"here4"<<endl;
        while(1) {
			char s[100];
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				query(a-1, b-1);
			} else {
				change(a-1, b);
			}
		}
    }




    return 0;
}
