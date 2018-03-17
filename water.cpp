#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    long long row;
    long long col;

}node;
long long arr[1000][1000];
long long visited[1000][1000];
long long path[1000][1000];
node move[4];
long long n,m;

long long bfs(long long i,long long j)
{
    queue<node> q;
    long long k,l,tempi,tempj,sum=0,min=999999,aa=0;
    memset(path,0,sizeof(path));
    node u,r,a[10000];
    u.row=i;
    u.col=j;
    q.push(u);

    while(!q.empty())
    { //cout<<"inside while"<<endl;
        u=q.front();
        q.pop();
        a[aa++]=u;
        visited[u.row][u.col]=1;
        path[u.row][u.col]=1;
        for(k=0;k<4;k++)
        {
            tempi=i+move[k].row;
            tempj=j+move[k].col;
            //cout<<tempi<<" "<<tempj<<endl;
            //cout<<arr[tempi][tempj]<<" "<<arr[u.row][u.col]<<endl;
            if(arr[tempi][tempj]<=arr[u.row][u.col]&&!visited[tempi][tempj])
            {
                if(tempi==0||tempj==0||tempi==(n-1)||tempj==(m-1))
                    return 0;


                r.row=tempi;
                r.col=tempj;
                q.push(r);
            }
            else if(!path[tempi][tempj])
            {
                if(min>arr[tempi][tempj])
                    min=arr[tempi][tempj];

            }
        }
    }

    aa--;
    while(aa>=0)
    {
        sum=sum+(min-arr[a[aa].row][a[aa].col]);
        aa--;
       // cout<<"aa reached , sum_aa :"<<sum<<endl;
    }
    return sum;
}

int main()
{
    long long test,i,j,k,sum=0;
    move[0].row=0;
    move[0].col=-1;
    move[1].row=-1;
    move[1].col=0;
    move[2].row=0;
    move[2].col=1;
    move[3].row=1;
    move[3].col=0;

    cin>>test;
    for(i=0;i<test;i++)
    {
        memset(visited,0,sizeof(visited));
        cin>>n>>m;
        for(j=0;j<n;j++)
            for(k=0;k<m;k++)
                cin>>arr[j][k];
        sum=0;
        for(j=1;j<n-1;j++)
        {
            for(k=1;k<m-1;k++)
            {
                if(!visited[j][k])
                    sum=sum+bfs(j,k);
                    //cout<<sum<<endl;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}








