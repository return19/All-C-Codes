#include<bits/stdc++.h>
using namespace std;

long long n,m,q;

long long pop[501000];

vector< vector<long long> > v(501000);

vector< pair<long long,long long> > e;

vector< vector<long long> > g(501000);

long long tk[501000];

long long qrs[501000][3];

long long vis[501000];

long long par[501000];
long long val[501000];

set< pair<long long,long long> > pq;

vector<long long> ans;

long long root(long long v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(long long x,long long y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

long long dfs(long long x)
{
    vis[x]=1;
    long long i,j,k;
    long long ans=pop[x];

    for(i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]]){
            ans+=dfs(g[x][i]);

            merge_dsu(x,g[x][i]);
        }
    }

    return ans;
}

int main()
{
    long long i,j,k;
    long long x,y;
    char t[5];

    scanf("%lld%lld%lld",&n,&m,&q);

    for(i=0;i<n;i++)
        par[i]=-1;

    for(i=0;i<n;i++)
    {
        scanf("%lld",&pop[i]);

        v[i].push_back(pop[i]);
    }

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);

        x--;
        y--;

        e.push_back(make_pair(x,y));
        tk[i]=1;
    }

    for(i=0;i<q;i++)
    {
        scanf("%s",t);

        if(t[0]=='D')
        {
            scanf("%lld",&x);
            x--;
            qrs[i][0]=1;
            qrs[i][1]=x;

            tk[x]=0;
        }
        else if(t[0]=='P')
        {
            scanf("%lld%lld",&x,&y);

            x--;
            qrs[i][0]=0;
            qrs[i][1]=x;
            qrs[i][2]=y;

            pop[x]=y;

            v[x].push_back(y);

        }
    }

    for(i=0;i<m;i++)
    {
        if(tk[i])
        {
            g[e[i].first].push_back(e[i].second);
            g[e[i].second].push_back(e[i].first);
        }
    }

    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            long long temp=dfs(i);
            val[root(i)]=temp;
            pq.insert(make_pair(temp,root(i)));
        }
    }

   /* for(i=0;i<n;i++)
    {
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }



    for(it1=pq.begin();it1!=pq.end();it1++)
    {
        cout<<it1->first<<" "<<it1->second<<endl;
    }*/
set< pair<long long,long long> >::iterator it1,it2;
    for(i=q-1;i>=0;i--)
    {
        it1=pq.end();
        it1--;
        ans.push_back(it1->first);

        if(qrs[i][0]==1) // D
        {
            x=e[qrs[i][1]].first;
            y=e[qrs[i][1]].second;

            if(root(x)!=root(y))
            {
                long long temp=val[root(x)] + val[root(y)];
                //it1=pq.find();
               // it2=pq.find();

                pq.erase(make_pair(val[root(x)],root(x)));
                pq.erase(make_pair(val[root(y)],root(y)));
                merge_dsu(x,y);

                val[root(x)]=temp;
                pq.insert(make_pair(temp,root(x)));
            }
        }
        else // P
        {
            x=qrs[i][1];
            y=qrs[i][2];

            long long chg=v[x][v[x].size()-2] - v[x][v[x].size()-1];
            v[x].pop_back();

            //it1=pq.find(make_pair(root(x),val[root(x)]));
            pq.erase(make_pair(val[root(x)],root(x)));
            val[root(x)]+=chg;
            pq.insert(make_pair(val[root(x)],root(x)));
        }
    }



    for(i=ans.size()-1;i>=0;i--)
        printf("%lld\n",ans[i]);

    return 0;
}












