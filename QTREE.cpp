#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int n;
int chainNo;
vector< pair<int,int> > g[1010000]; // node,cost
int vis[1010000];
int subtree[1010000];
int chainHead[101000],chainInd[1010000];
int base[1010000],pos[1010000],ptr;
int depth[1010000];
int pa[25][1010000];
int st[5010000];
int otherEnd[1010000];
vector<int> index1[1010000];

void build(int idx,int l,int r){
    if(l>r) return;
    if(l==r){
        st[idx]=base[l];
        return;
    }
    int mid= l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    st[idx]=max(st[(idx<<1)+1],st[(idx<<1)+2]);
}

void update(int idx,int l,int r,int x,int val){
    if(l>r)
        return;
    if(x<l || r<x)
        return;
    if(l==r && l==x){
        st[idx]=val;
        return;
    }
    int mid = l + (r-l)/2;
    update((idx<<1)+1,l,mid,x,val);
    update((idx<<1)+2,mid+1,r,x,val);
    st[idx]=max(st[(idx<<1)+1],st[(idx<<1)+2]);
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>r)
        return INT_MIN;
    if(qr<l || r<ql)
        return INT_MIN;
    if(ql<=l && r<=qr)
        return st[idx];
    int mid = l + (r-l)/2;
    return max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
}

int queryUp(int u,int v){
    if(u==v)    return 0;
    int uchain,vchain=chainInd[v];
    int ans=INT_MIN;
    while(1){
        uchain=chainInd[u];
        if(uchain == vchain){
            int temp = query(0,0,ptr-1,pos[v],pos[u]);
            ans=max(ans,temp);
            break;
        }
        int temp = query(0,0,ptr-1,pos[chainHead[u]],pos[u]);
        ans=max(ans,temp);
        u=chainHead[uchain];
        u=pa[0][u];
    }
    return ans;
}

int lca(int u,int v){
    if(u==v)    return u;
    if(depth[u]<depth[v])   swap(u,v);
    int diff=depth[u]-depth[v];
    int i,j,k;
    for(i=0;i<16;i++){
        if((diff>>i)&1)
            u=pa[i][u];
    }
    if(u==v)    return u;
    for(i=15;i>=0;i--){
        if(pa[i][u]!=pa[i][v]){
            u=pa[i][u];
            v=pa[i][v];
        }
    }
    return pa[0][u];
}

void hld(int cur,int cost){
    vis[cur]=1;
    if(chainHead[chainNo]==-1){
        chainHead[chainNo]=cur;
    }
    chainInd[cur]=chainNo;
    pos[cur]=ptr;
    base[ptr++]=cost;

    int i,j,k;
    int sc=-1,c;

    for(i=0;i<g[cur].size();i++){
        if(!vis[g[cur][i].ft])
            if(sc==-1 || subtree[sc]<subtree[g[cur][i].ft]){
                sc=g[cur][i].ft;
                c=g[cur][i].sd;
            }
    }
    if(sc!=-1)
        hld(sc,c);

    for(i=0;i<g[cur].size();i++){
        if(!vis[g[cur][i].ft] && g[cur][i].ft!=sc){
            chainNo++;
            hld(g[cur][i].ft,g[cur][i].sd);
        }
    }
}

int dfs(int x,int d){
    vis[x]=1;
    int i,j,k;
    subtree[x]=1;
    depth[x]=d;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i].ft]){
            subtree[x]+=dfs(g[x][i].ft,d+1);
            otherEnd[index1[x][i]]=g[x][i].ft;
        }
    }
    return subtree[x];
}

int main()
{
    int i,j,k;
    int test,t;
    int x,y,z;

    //scanf("%d",&test);
    scanint(test);
    for(t=0;t<test;t++)
    {

        //scanf("%d",&n);
        scanint(n);
        for(i=0;i<n;i++){
            g[i].resize(0);
            index1[i].resize(0);
        }
        ptr=0;
        chainNo=0;

        for(i=0;i<n-1;i++){
            //scanf("%d%d%d",&x,&y,&z);
            scanint(x);
            scanint(y);
            scanint(z);
            x--;    y--;
            g[x].push_back(mp(y,z));
            g[y].push_back(mp(x,z));
            index1[x].push_back(i);
            index1[y].push_back(i);
        }

        for(i=0;i<16;i++)
            for(j=0;j<n;j++){
                if(pa[i-1][j]!=-1)
                    pa[i][j]=pa[i-1][pa[i-1][j]];
            }

        for(i=0;i<n;i++)    vis[i]=0;
        dfs(0,0);
        for(i=0;i<n;i++)    vis[i]=0;
        chainNo=0;
        hld(0,0);
        build(0,0,ptr-1);

        char s[10];
        scanf("%s",s);
        while(s!="DONE"){
            scanf("%d%d",&x,&y);
            if(s[0]=='Q'){ // query
                int lca1 = lca(x,y);
                x--;    y--;
                int ans = max(queryUp(y,lca1),
                              queryUp(x,lca1));
                printf("%d\n",ans);
            }else{// update
                x--;
                update(0,0,ptr-1,pos[otherEnd[x]],y);
            }
            cin>>s;
        }
    }

    return 0;
}
