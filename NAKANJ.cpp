#include<bits/stdc++.h>
using namespace std;

int a,b;
int x,y;

int ans;


pair<int,int> p,p1;
pair< pair<int,int>,int > pp;

int move1[10][10]={
                   {-1,-2},
                   {-2,-1},
                   {-2,1},
                   {-1,2},
                   {1,2},
                   {2,1},
                   {2,-1},
                   {1,-2}
                };

int visited[10][10];

int bfs()
{
    queue< pair<pair<int,int>,int> > q;
    //cout<<"one"<<endl;

    int i,j,k;

    int temp_a,temp_b;
    int temp_x,temp_y;

    p.first=a;
    p.second=b;


    q.push(make_pair(p,0));
    //cout<<"two"<<endl;



    while(!q.empty())
    {
        pp=q.front();
        q.pop();

        temp_a=pp.first.first;
        temp_b=pp.first.second;

        visited[temp_a][temp_b]=1;

        for(i=0;i<8;i++)
        {
            temp_x=temp_a+move1[i][0];
            temp_y=temp_b+move1[i][1];

            if(temp_x>=1&&temp_x<=8&&temp_y>=1&&temp_y<=8&&!visited[temp_x][temp_y])
            {
                if(temp_x==x&&temp_y==y)
                {
                    return pp.second;
                }



                p1.first=temp_x;
                p1.second=temp_y;
                q.push(make_pair(p1,pp.second+1));
            }
        }
    }

}

int main()
{
    int i,j,k,test;
    char str[10];

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {

        memset(visited,0,sizeof(visited));

        scanf("%s",str);
        //cout<<str<<endl;

         //cout<<"one"<<endl;
        b=str[0]-'a'+1;
        a=str[1]-'0';

        scanf("%s",str);
        //scanf("%s",str);
        //cout<<str<<endl;

        y=str[0]-'a'+1;
        x=str[1]-'0';

        //cout<<a<<" "<<b<<"   "<<x<<" "<<y<<endl;

        if(a==x&&b==y)
        {
            printf("0\n");
            continue;
        }

        ans=bfs();

        printf("%d\n",ans+1);
    }

    return 0;
}
