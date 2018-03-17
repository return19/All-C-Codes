#include<bits/stdc++.h>
using namespace std;
#define MAX 32000

typedef struct ll
{
    int horz;
    int vert;
}moves;

moves move1[4];

int arr[210][210];
int visited[210][210];
int dist[210][210];
int n,m;
queue< pair<int,int> > q;


void init()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j])
            {
                dist[i][j]=0;
            }
            else
                dist[i][j]=MAX;
        }
    }
}


void bfs()
{
    int i,j,k,x,y;
    pair<int,int> p,temp;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        visited[p.first][p.second]=1;

        for(i=0;i<4;i++)
        {
            x=p.first+move1[i].horz;
            y=p.second+move1[i].vert;

            if(!visited[x][y]&&dist[x][y]!=0&&x>=0&&x<n&&y>=0&&y<m)
            {
                visited[x][y]=1;
                dist[x][y]=dist[p.first][p.second]+1;
                temp.first=x;
                temp.second=y;
                q.push(temp);
            }
        }
    }
}

int main()
{
    int test,i,j,k,num;
    pair<int,int> p;

    move1[0].horz=0;
    move1[0].vert=-1;

    move1[1].horz=0;
    move1[1].vert=1;

    move1[2].horz=-1;
    move1[2].vert=0;

    move1[3].horz=1;
    move1[3].vert=0;

    cin>>test;
   // scanf("%lld",&test);
    for(i=0;i<test;i++)
    {

        cin>>n;
        cin>>m;
        // scanf("%lld",&n);
          //scanf("%lld",&m);
        for(j=0;j<n;j++)
        {
            cin>>num;
             //scanf("%lld",&num);
            for(k=m-1;k>=0;k--)
            {
                arr[j][k]=num%10;
                if(arr[j][k]==1)
                {
                    p.first=j;
                    p.second=k;
                    q.push(p);
                    visited[j][k]=0;
                    dist[j][k]=0;
                }
                else{
                    visited[j][k]=0;
                    dist[j][k]=MAX;
                }
                num=num/10;
            }
        }
        //cout<<"reached"<<endl;
        bfs();
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                //printf("%lld ",dist[j][k]);
                cout<<dist[j][k]<<" ";
            }
           //printf("\n");
           cout<<endl;
        }


    }
    return 0;
}








