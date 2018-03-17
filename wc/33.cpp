#include<bits/stdc++.h>
using namespace std;

int n,m,k;

vector<int> v[201000]; // original graph
vector<int> tr[201000]; // transpose graph
vector<int> ng[201000]; // new graph of scc ...each scc as one node
map<int,int> nodes; // whether or not a node is required in final answer

vector<int> scc[201000];//2d vector with each vector containing a scc
int scc_t[201000];//whether a scc contains any required node or not...1 if it does else 0
vector<int> tso;// scc newgraph in topsort order
int s1=0;
int cur=0;

int visited[201000];
int ans=0;
int cnt=0;

int order[201000];
int O=0;

stack<int> s;

stack<int> ts;

map<int,int> memo;
map<int,int>::iterator it;

map< pair<int,int>,int > memo2;

void dfs_scc(int x)
{
    int i;
    visited[x]=1;

    for(i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]])
            dfs_scc(v[x][i]);
    }

    s.push(x);
}

void dfs(int x)
{
    int i,j;

    visited[x]=1;
    scc[s1].push_back(x);

    memo[x]=s1+1;

    if(nodes[x]==1)
        scc_t[s1+1]=1;

    for(i=0;i<tr[x].size();i++)
    {
        if(!visited[tr[x][i]])
        {
            dfs(tr[x][i]);
        }
    }
}

void find_scc()
{
    int i,j;

    for(i=1;i<=n;i++)
        visited[i]=0;

    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs_scc(i);
        }
    }


    for(i=0;i<=n;i++)
        tr[i].resize(0);

    //find transpose of graph

    for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            tr[v[i][j]].push_back(i);

        }
    }

    for(i=0;i<=n;i++)
        visited[i]=0;

    s1=0;
    memo.clear();
    cnt=0;
    int u;

    for(i=0;i<=n;i++)
        scc[i].resize(0);

    while(!s.empty())
    {
        u=s.top();
        s.pop();

        //cout<<u<<" ";

        if(!visited[u])
        {
            scc_t[s1+1]=0;
            dfs(u);
            //stores scc in scc vector
            if(scc_t[s1+1]==1)
                cnt++;

            s1++;
        }
    }
    //cout<<endl;
    // sort elements in each scc for lexicographic order
    for(i=0;i<s1;i++)
        sort(scc[i].begin(),scc[i].end());

     /*cout<<endl;

    for(i=0;i<s1;i++)
    {
        for(j=0;j<scc[i].size();j++)
            cout<<scc[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
}

void dfs_ts(int x)
{
    int i,j;

    visited[x]=1;

    for(i=0;i<ng[x].size();i++)
    {
        //cout<<x<<" "<<ng[x][i]<<endl;

        if(!visited[ng[x][i]])
            dfs_ts(ng[x][i]);
    }
   // cout<<x<<endl;
    ts.push(x);
}

void topsort()
{
    int i,j;

    for(i=0;i<=s1;i++)
        visited[i]=0;

    for(i=1;i<=s1;i++)
    {
        if(!visited[i])
        {
            dfs_ts(i);
        }
    }

    tso.resize(0);

    while(!ts.empty())
    {
        tso.push_back(ts.top());
        ts.pop();
    }
}

void new_graph()
{
    int i,j;
    int x,y;
    int u;
    int sz=0;

    for(i=0;i<=s1;i++)
        ng[i].resize(0);

    memo2.clear();

    for(it=memo.begin();it!=memo.end();it++)
    {
        u=it->first;

        for(j=0;j<v[u].size();j++)
        {
            if(memo[u]!=memo[v[u][j]])
            {
                if(memo2[make_pair(memo[u],memo[v[u][j]])]==0)
                {
                    memo2[make_pair(memo[u],memo[v[u][j]])]=1;

                    ng[memo[u]].push_back(memo[v[u][j]]);
                }
            }
        }
    }



}

int f=0;

void dfs_ans(int x)
{
    int i,j;

    if(scc_t[x]==1){
        order[O]=x;
        O++;
    }

    visited[x]=1;

    for(i=0;i<ng[x].size();i++)
    {
        if(!visited[ng[x][i]])
        {
            dfs_ans(ng[x][i]);
        }
    }

    if(f==1)
        return;

    if(O!=cnt)
    {
        if(scc_t[x]==1)
            O--;
        visited[x]=0;
    }
    else
    {
        f=1;
    }
}

void find_ans()
{
    O=0;
    int i,j;

    for(i=0;i<=s1;i++)
        visited[i]=0;

    dfs_ans(tso[cur]);
}

int main()
{
    int i,j,test;
    int x,y;
    int t;


    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        f=0;

        scanf("%d%d%d",&n,&m,&k);

        nodes.clear();

        for(i=0;i<k;i++){
            scanf("%d",&x);
            nodes[x]=1;
        }

        for(i=0;i<=n;i++)
            v[i].resize(0);

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }

        find_scc();

        cur=0;

        // new graph ng with each scc represented as one node
        new_graph();

        // top sort that ng graph
        topsort();

        map<int,int> m;

        for(i=0;i<tso.size();i++)
        {
            if(scc_t[tso[i]]==1)
            {
                cur=i;
                break;
            }
        }

        int c3=0;

        m[tso[cur]]=1;

        for(i=cur;i<tso.size();i++)
        {
           /* for(map<int,int>:: iterator it=m.begin();it!=m.end();it++)
                cout<<it->first<<" ";
            cout<<endl;*/

            if(m[tso[i]]==1&&scc_t[tso[i]]==1)
            {
                c3++;
                cur=i;
                m.clear();

                    //cout<<i<<" : ";

                    for(j=0;j<ng[tso[i]].size();j++)
                        {
                            m[ng[tso[i]][j]]=1;
                         //   cout<<ng[tso[i]][j]<<" ";
                        }
                       // cout<<endl;

                continue;
            }
            else if(scc_t[tso[i]]==1&&m[tso[i]]==0)
            {
                //cout<<"here "<<i<<endl;
                f=0;
                break;
            }

            if(m[tso[i]]==1)
            {
                for(j=0;j<ng[tso[i]].size();j++)
                    m[ng[tso[i]][j]]=1;
            }

        }

        //cout<<i<<endl;

        if(c3==cnt)
            f=1;
        else
            f=0;

        /*for(i=0;i<tso.size();i++)
            cout<<tso[i]<<" ";
        cout<<endl;

        for(i=0;i<tso.size();i++)
            cout<<scc_t[tso[i]]<<" ";
        cout<<endl;*/




        /*for(i=0;i<tso.size();i++)
            cout<<tso[i]<<" ";
        cout<<endl;

        for(i=1;i<=s1;i++)
            for(j=0;j<ng[i].size();j++)
                cout<<i<<" "<<ng[i][j]<<endl;

        cout<<"cnt : "<<cnt<<endl;*/

        // here is the problem....how to know whether there is a soln or not
        // if there is solution then the algo hopefully gives right answer
        // but if there is no solution then if should answer -1




       /* for(i=0;i<s1;i++)
            {
                for(j=0;j<scc[tso[i]-1].size();j++)
                    cout<<scc[tso[i]-1][j]<<" ";
            }
        cout<<endl;*/



        //find_ans();

        if(f==0)
        {
            printf("-1\n");
        }
        else
        {
            for(i=0;i<tso.size();i++)
            {
                for(j=0;j<scc[tso[i]-1].size();j++)
                    if(nodes[scc[tso[i]-1][j]]==1)
                        printf("%d ",scc[tso[i]-1][j]);
            }

            printf("\n");
        }
    }

    return 0;
}
