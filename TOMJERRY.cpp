#include<bits/stdc++.h>
using namespace std;

int arr[1010][1010];
int n,k;
int move_x[5]={0,-1,0,1};
int move_y[5]={-1,0,1,0};

int j_x,j_y;

typedef struct e
{
    int x,y;
    int n;
    int k;
    map< pair<int,int>,int > memo;

}elem;
int db=0;
int solve()
{
    queue<elem> q;

    pair<int,int> p;
    elem t,t1;
    int i,j;

    t.x=0;
    t.y=0;
    t.n=0;
    t.k=0;


    q.push(t);

    while(1)
    {

        t=q.front();
        q.pop();



        for(i=0;i<4;i++)
        {
            int temp_x=t.x+move_x[i];
            int temp_y=t.y+move_y[i];



            if(temp_x>=0&&temp_y<n&&temp_y>=0&&temp_y<n&&arr[temp_x][temp_y]!=-1)
            {
                if(temp_x==j_x&&temp_y==j_y&&t.k==k)
                    return t.n+1;

                t1.x=temp_x;
                t1.y=temp_y;
                t1.n=t.n+1;

                p.first=temp_x;
                p.second=temp_y;

                if(arr[temp_x][temp_y]==5)
                {
                    //t1.n=t.n+1;

                    if(t.memo[p]==1)
                    {
                        t1.memo=t.memo;
                        t1.k=t.k;
                        //cout<<"#1 "<<temp_x<<" "<<temp_y<<endl;
                        q.push(t1);
                    }
                    else
                    {
                        t1.memo=t.memo;
                        t1.memo[p]=1;
                        t1.k=t.k+1;
                        //cout<<"#2 "<<temp_x<<" "<<temp_y<<endl;
                        q.push(t1);
                    }
                }
                else
                {
                    //t1=t;
                    t1.memo=t.memo;
                    t1.k=t.k;
                   // cout<<"# "<<temp_x<<" "<<temp_y<<endl;
                    q.push(t1);
                }

            }
        }

    }



}

int main()
{
    int i,j;


    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);

            if(arr[i][j]==7)
            {
                j_x=i;
                j_y=j;
            }
        }
    }


    cout<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);

        }

        cout<<endl;
    }

    int ans=solve();

    cout<<ans<<endl;

    return 0;
}













