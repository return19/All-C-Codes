#include<bits/stdc++.h>
using namespace std;

int sstart[110];


int lstart[110];


int visited[110];

int n,m;

int bfs(int x)
{
    int i,j,k;
    int ans=99999999;

    pair<int,int> p;

    queue< pair<int,int> > q;

    q.push(make_pair(x,0));

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        visited[p.first]=1;

       // cout<<"here : "<<p.first<<" "<<p.second<<endl;

        int f=0;

        if(p.first==99)
            {
               return p.second;
            }

        for(i=6;i>0;i--)
        {



            if(p.first+i>99)
                continue;


            if(p.first+i==99)
            {
                return p.second+1;
            }

            if(visited[p.first+i])
                continue;

            if(lstart[p.first+i]){
                q.push(make_pair(lstart[p.first+i],p.second+1));
                continue;
            }

            if(sstart[p.first+i])
            {

                q.push(make_pair(sstart[p.first+i],p.second+1));

                continue;
            }

            q.push(make_pair(p.first+i,p.second+1));
        }
    }

    return -1;
}


int main()
{
    int test,i,j,k;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        memset(lstart,0,sizeof(lstart));
        memset(sstart,0,sizeof(sstart));
        memset(visited,0,sizeof(visited));

        for(j=0;j<n;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            lstart[x]=y;

        }

        scanf("%d",&m);

        for(j=0;j<m;j++)
        {
            int x,y;

            scanf("%d%d",&x,&y);

            x--;
            y--;

            sstart[x]=y;
        }

        int ans=bfs(0);

        if(ans==99999999)
        {
            printf("-1\n");

        }
        else
            printf("%d\n",ans);
    }

    return 0;
}
