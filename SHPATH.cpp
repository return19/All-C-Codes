#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
long graph[10010][10010];
//long dist[10010];
long visited[10010];
long v,start;

typedef struct ll
{
    long dist[10010];
}d;

map<long,d> memo_dist;
map<string,long> memo;
map<long,long> memo_for_dist;
long minDistance()
{
    long min=MAX,i,min_index;
    for(i=0;i<v;i++)
    {
        if(!visited[i]&&min>=memo_dist[start].dist[i]){
            min=memo_dist[start].dist[i];
            min_index=i;
        }

    }
    return min_index;
}

void dijkstra(long src)
{
    long i,j,u;
    memset(visited,0,sizeof(visited));
    //memset(dist,MAX,sizeof(dist));
    memset(memo_dist[start].dist,0,sizeof(memo_dist[start].dist));
    memo_dist[start].dist[src]=0;

    for(i=0;i<v;i++)
    {
        u=minDistance();
        visited[u]=1;

        for(j=0;j<v;j++)
        {
            if(!visited[j]&&memo_dist[start].dist[u]+graph[u][j]<memo_dist[start].dist[j]&&memo_dist[start].dist[u]!=MAX&&graph[u][j])
            {
                memo_dist[start].dist[j]=memo_dist[start].dist[u]+graph[u][j];
            }
        }
    }
}

int main()
{
    long test,i,j,k,query,w,last,edges;
    char city[21],city1[21],city2[21];
    //cin>>test;
    scanf("%ld",&test);

    for(i=0;i<test;i++)
    {
        //cin>>v;
        scanf("%ld",&v);
        memset(graph,0,sizeof(graph));
        //memset(memo,0,sizeof(memo));
        //memset(memo_for_dist,0,sizeof(memo_for_dist));

        for(j=0;j<v;j++)
        {
            //cin>>city;
            scanf("%s",city);
            memo[city]=j;

            //cin>>edges;
            scanf("%ld",&edges);
            for(k=0;k<edges;k++)
            {
                //cin>>last;
                //cin>>w;
                scanf("%ld",&last);
                scanf("%ld",&w);
                graph[j][last-1]=w;
            }
        }

        //cin>>query;
        scanf("%ld",&query);
        for(j=0;j<query;j++)
        {
            //cin>>city1;
            scanf("%s",city1);
            start=memo[city1];
            //cin>>city2;
            scanf("%s",city2);
            last=memo[city2];
            //cout<<"start :"<<start<<"\t\t"<<"last :"<<last<<endl;
            if(memo_for_dist[start]==i)
            {
                printf("%ld\n",memo_dist[start].dist[last]);
            }
            else{
            dijkstra(start);
            //for(k=0;k<v;k++) cout<<dist[k]<<endl;
            //cout<<dist[last]<<endl;
            printf("%ld\n",memo_dist[start].dist[last]);
            memo_for_dist[start]=i;
            }
        }

    }
}












