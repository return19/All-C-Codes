#include<bits/stdc++.h>
using namespace std;

int n,m,k;

//vector<int> v[101000]; // original graph
//vector<int> tr[101000]; // transpose graph
//vector<int> ng[101000]; // new graph of scc ...each scc as one node
int nodes[101000]; // whether or not a node is required in final answer

//vector<int> scc[101000];//2d vector with each vector containing a scc
int scc_t[101000];//whether a scc contains any required node or not...1 if it does else 0
int tso[101000];// scc newgraph in topsort order
int s1=0;
int cur=0;

int visited[101000];
int ans=0;
int cnt=0;

int order[101000];
int O=0;

stack<int> s;

stack<int> ts;

int memo[101000];
int it;



void dfs_scc(int x,vector<int> v[])
{
    int i;
    visited[x]=1;

    for(i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]])
            dfs_scc(v[x][i],v);
    }

    s.push(x);
}

void dfs(int x,vector<int> tr[],vector<int> scc[])
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
            dfs(tr[x][i],tr,scc);
        }
    }
}

void find_scc(vector<int> v[],vector<int> tr[],vector<int> scc[])
{
    int i,j;

    for(i=1;i<=n;i++)
        visited[i]=0;

    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs_scc(i,v);
        }
    }


//    for(i=0;i<=n;i++)
  //      tr[i].resize(0);

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

    for(i=0;i<=n;i++)
        memo[i]=0;

    cnt=0;
    int u;

    //for(i=0;i<=n;i++)
      //  scc[i].resize(0);

    while(!s.empty())
    {
        u=s.top();
        s.pop();

        //cout<<u<<" ";

        if(!visited[u])
        {
            scc_t[s1+1]=0;
            dfs(u,tr,scc);
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

void dfs_ts(int x,vector<int> ng[])
{
    int i,j;

    visited[x]=1;

    for(i=0;i<ng[x].size();i++)
    {
        //cout<<x<<" "<<ng[x][i]<<endl;

        if(!visited[ng[x][i]])
            dfs_ts(ng[x][i],ng);
    }
   // cout<<x<<endl;
    ts.push(x);
}

void topsort(vector<int> ng[])
{
    int i,j;

    for(i=0;i<=s1;i++)
        visited[i]=0;

    for(i=1;i<=s1;i++)
    {
        if(!visited[i])
        {
            dfs_ts(i,ng);
        }
    }

    i=0;

    while(!ts.empty())
    {
        tso[i]=ts.top();
        i++;
        ts.pop();
    }
}

void new_graph(vector<int> v[],vector<int> ng[])
{
    int i,j;
    int x,y;
    int u;
    int sz=0;

    for(i=0;i<=s1;i++)
        ng[i].resize(0);

    //memo2.clear();

    for(it=1;it<=n;it++)
    {
        u=it;

        for(j=0;j<v[u].size();j++)
        {
            if(memo[u]!=memo[v[u][j]])
            {

                    ng[memo[u]].push_back(memo[v[u][j]]);

            }
        }
    }



}

int f=0;

void dfs_ans(int x,vector<int> ng[])
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
            dfs_ans(ng[x][i],ng);
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

void find_ans(vector<int> ng[])
{
    O=0;
    int i,j;

    for(i=0;i<=s1;i++)
        visited[i]=0;

    dfs_ans(tso[cur],ng);
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



        for(i=0;i<=n;i++)
            nodes[i]=0;

        for(i=0;i<k;i++){
            scanf("%d",&x);
            nodes[x]=1;
        }

        vector<int> v[n+5];
        vector<int> tr[n+5]; // transpose graph

       // for(i=0;i<=n;i++)
         //   v[i].resize(0);

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }

        vector<int> scc[n+5];

        find_scc(v,tr,scc);

        cur=0;

        vector<int> ng[s1+5];

        // new graph ng with each scc represented as one node
        new_graph(v,ng);
        // top sort that ng graph
        topsort(ng);

        for(i=0;i<s1;i++)
            {
                if(scc_t[tso[i]]==1)
                {
                    cur=i;
                    break;
                }
            }

        map<int,int> m;

        m[tso[cur]]=1;
            int c3=0;

        for(i=cur;i<s1;i++)
        {
            if(m[tso[i]]==1&&scc_t[tso[i]]==1)
            {
                c3++;



                for(j=0;j<ng[i].size();j++)
                    m[ng[i][j]]=1;

                cur=i;

                continue;
            }
            else if(m[tso[i]]==0&&scc_t[tso[i]]==1)
            {
                break;
            }
            else
            {
                if(m[tso[i]]==1)
                {
                    for(j=0;j<ng[i].size();j++)
                        m[ng[i][j]]=1;
                }
            }
        }


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


        //find_ans(ng);

        if(f==0)
        {
            printf("-1\n");
        }
        else
        {
            for(i=0;i<s1;i++)
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
