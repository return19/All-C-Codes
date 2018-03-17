#include<bits/stdc++.h>
using namespace std;

int graph[1010][1010];

int p[1010];

int n,m,q;

int roads[1010][2];

int vis[1010];
int num;
int ans_n;
int ans;
int cc[1010];

int dfs(int x)
{
    //cout<<"here "<<x<<endl;

    vis[x]=1;
    cc[x]=num;

    int i,j,k;

    int ans=p[x];

    for(i=0;i<n;i++)
    {
        if(!vis[i] && graph[x][i])
            ans += dfs(i);
    }

    return ans;
}

int main()
{
    int test,i,j,k,t;

    string tp;
    int x,y;

    //scanf("%d",&test);
    test=1;
    for(t=0;t<test;t++)
    {
        scanf("%d%d%d",&n,&m,&q);
        //cout<<n<<" "<<m<<" "<<q<<endl;
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);

            x--;
            y--;

            roads[i][0]=x;
            roads[i][1]=y;

            graph[x][y]=1;
            graph[y][x]=1;
        }

       // cout<<"out"<<q<<endl;
        ans=INT_MIN;
        for(i=0;i<q;i++)
        {
            cin>>tp;
           // cout<<"ha"<<endl;

            //cout<<tp<<endl;

            if(tp[0]=='P')
            {
                //cout<<"here"<<endl;
                scanf("%d%d",&x,&y);

                x--;

                if(ans==INT_MIN)
                {
                    p[x]=y;
                    num=0;

                    ans=INT_MIN;

                        for(j=0;j<n;j++)
                            vis[j]=0;

                        for(j=0;j<n;j++)
                        {
                            if(!vis[j])
                            {
                                num=j;
                                int temp=dfs(j);

                                if(ans<temp)
                                {
                                    ans=temp;
                                    ans_n=num;
                                }
                            }
                        }
                }
                else
                {
                     if(cc[x]==ans_n)
                    {
                        ans+=(y-p[x]);
                    }
                    p[x]=y;
                }


            }
            else
            {
                scanf("%d",&x);
                x--;
                graph[roads[x][0]][roads[x][1]]=0;
                graph[roads[x][1]][roads[x][0]]=0;

                num=0;

                ans=INT_MIN;

                    for(j=0;j<n;j++)
                        vis[j]=0;

                    for(j=0;j<n;j++)
                    {
                        if(!vis[j])
                        {
                            num=j;
                            int temp=dfs(j);

                            if(ans<temp)
                            {
                                ans=temp;
                                ans_n=num;
                            }
                        }
                    }
            }

                printf("%d\n",ans);
        }
    }

    return 0;
}
