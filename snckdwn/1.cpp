#include<bits/stdc++.h>
using namespace std;


int n;
int x,y,x1,y11,x2,y2;

int move_x[4]={-1,0,1,0};
int move_y[4]={0,1,0,-1};

pair<int,int> p,pp;
pair< pair <int,int> , int > p1,ppp;

int solve()
{
    int i,j,k;
    int temp_x,temp_y;
    int val;


    queue< pair< pair<int,int> , int> > q;

    p.first=x;
    p.second=y;
    p1.first=p;
    p1.second=0;

    q.push(p1);

    int c=0;

    while(!q.empty())
    {   c++;
        if(c==10)
            return -50;
        //cout<<"here"<<endl;

        p1=q.front();
        q.pop();
        p=p1.first;
        val=p1.second;
        //cout<<val<<endl;


        for(i=0;i<4;i++)
        {
            temp_x=move_x[i]+p.first;
            temp_y=move_y[i]+p.second;

            //cout<<temp_x<<" "<<temp_y<<endl;

            if((temp_x!=x2&&temp_y!=y2)){
                if(temp_x>=1&&temp_x<=n&&temp_y>=1&&temp_y<=n)
                {
                    if(temp_x==x1&&temp_y==y11)
                    {
                        return (val+1);
                    }
                    pp.first=temp_x;
                    pp.second=temp_y;
                    ppp.first=pp;
                    ppp.second=val+1;
                    q.push(ppp);
                }
            }
        }
    }

    return -1;


}

int main()
{
    int test,i,j,k;
    int ans;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        scanf("%d%d",&x,&y);
        scanf("%d%d",&x1,&y11);
        scanf("%d%d",&x2,&y2);

        ans=solve();

        printf("%d\n",ans);
    }

    return 0;
}
