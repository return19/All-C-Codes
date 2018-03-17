#include<bits/stdc++.h>
#define MAX 1e8//very large number
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{int V;
 cin>>V;//Number of vertices

 vvii G(V);//The weighted undirected graph

 vector<bool>disc(V,false);//whether the vertex is discovered or not

 vi d(V,MAX);//all d[] initialised

 vi par(V,-1);//parent of the vertex

 vii edge;//The edges of the MST
 int E;
 cout<<"Edges\n";
 cin>>E;
 cout<<"Input every edge\n";

 for(int i=0;i<E;i++)
 {int u,v,wt;
      cin>>u;
      cin>>v;
      cin>>wt;

      u--;
      v--;

      G[u].push_back(make_pair(v,wt));
      G[v].push_back(make_pair(u,wt));
  }
      cout<<"Choose start vertex from 1 to "<<V<<endl;
      int s;
      cin>>s;

      s--;

      set<ii> Q;

      for(int i=0;i<V;i++)
        Q.insert(make_pair(d[i],i));
      Q.erase(Q.find(make_pair(d[s],s)));
      d[s]=0;
      Q.insert(make_pair(d[s],s));
      while(!Q.empty())
      {
           ii top=*Q.begin();
           Q.erase(Q.begin());

           int v=top.second;
           disc[v]=true;

           if(v!=s)
                edge.push_back(make_pair(par[v],v));

           for(int i=0;i<G[v].size();i++)
           {
               if(disc[G[v][i].first]==false)
                {
                    int v2=G[v][i].first;
                    int cost=G[v][i].second;

                    if(d[v2]>cost)
                    {     Q.erase(Q.find(make_pair(d[v2],v2)));
                          d[v2]=cost;
                          Q.insert(make_pair(d[v2],v2));
                          par[v2]=v;
                    }
                }
            }
    }

  cout<<"MST edge set is"<<endl;

  for(int i=0;i<edge.size();i++)
    cout<<edge[i].first+ 1<<","<<edge[i].second +1<<endl;

  return 0;
}
