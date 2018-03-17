#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int graph[210][210];
int reach[210][210];
vector<int> arr;
int visited[210];
int n,m;


int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}


queue< pair<pair< vector<int> ,int>,int> > q;
    pair< vector<int> ,int> p1,p2;
    pair< pair<vector<int>,int>,int > P1,P2;

    vector<int> v1,v2;


template <class InIt>
bool is_sorted(InIt b, InIt e) {
    if (b == e)           // No items -- sorted by definition
        return true;

    typename std::iterator_traits<InIt>::value_type first = *b;
    ++b;
    while (b != e) {    // skip if e-b == 1 (single item is sorted)
        if (*b < first)
            return false;
        first = *b;
        ++b;
    }
    return true;
}


void dfs(int i,int n)
{
    int j,k;
    visited[i]=1;

    for(j=0;j<m;j++)
    {
        //cout<<"dfs"<<endl;
        if(graph[i][j]&&!visited[j])
        {
            reach[n][j]=1;
            reach[j][n]=1;
            dfs(j,n);
        }
    }
}

void find_r()
{
    int i,j,k;

    for(i=0;i<m;i++)
    {
        memset(visited,0,sizeof(visited));
        //cout<<"find1"<<endl;
        reach[i][i]=1;
        dfs(i,i);
    }

   /* for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<reach[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

int solve2()
{

    int i,j,k;
    /*queue< pair<pair< vector<int> ,int>,int> > q;
    pair< vector<int> ,int> p1,p2;
    pair< pair<vector<int>,int>,int > P1,P2;

    vector<int> v1,v2;*/

    int c1=0,c2=0;

    v1=arr;
    p1.first=v1;
    p1.second=0;

    P1.first=p1;
    P1.second=m-1;

    q.push(P1);

    while(!q.empty())
    {
        //cout<<"queue"<<endl;
        P1=q.front();
        q.pop();

        p1=P1.first;

        v1=p1.first;
        c1=p1.second;
        c2=P1.second;

        //cout<<"here c2 : "<<c2<<endl;

        if(c2==m-1)
        {
            for(i=m-1;i>=0;i--)
            {
                if(reach[v1[m-1]][i]==1)
                {
                   // cout<<"i : "<<i<<endl;
                    v2=v1;
                    v2[m-1]=i;
                    p2.first=v2;

                    /*for(j=0;j<n;j++)
                        cout<<v2[j]<<" ";
                    cout<<endl;
                    cout<<"again c2:"<<c2<<endl;*/

                    if(is_sorted(v2.begin(),v2.end()))
                    {
                        return 1;
                    }

                    if(v1[m-1]!=i)
                    {
                        p2.second=1;
                    }
                    else
                    {
                        p2.second=0;
                    }
                    P2.first=p2;
                    P2.second=m-2;
                    q.push(P2);

                }

            }
        }
        else
        {
             for(i=m-1;i>=0;i--)
            {
                if(reach[v1[c2]][i]==1&&v1[c2+1]>=i)
                {
                    //cout<<"i : "<<i<<endl;

                    v2=v1;
                    v2[c2]=i;
                    p2.first=v2;

                    /*for(j=0;j<n;j++)
                        cout<<v2[j]<<" ";
                    cout<<endl;
                    cout<<"again c2:"<<c2<<endl;*/

                    if(is_sorted(v2.begin(),v2.end()))
                    {
                        return c1+1;
                    }

                    if(v1[c2]!=i)
                    {
                        p2.second=c1+1;
                    }
                    else
                    {
                        p2.second=c1;
                    }
                    P2.first=p2;
                    P2.second=c2-1;
                    q.push(P2);

                }

            }
        }

    }


    return -1;
}

int solve()
{

    int i,j,k;
    /*queue< pair<pair< vector<int> ,int>,int> > q;
    pair< vector<int> ,int> p1,p2;
    pair< pair<vector<int>,int>,int > P1,P2;

    vector<int> v1,v2;*/

    int c1=0,c2=0;

    v1=arr;
    p1.first=v1;
    p1.second=0;

    P1.first=p1;
    P1.second=0;

    q.push(P1);

    while(!q.empty())
    {
        //cout<<"queue"<<endl;
        P1=q.front();
        q.pop();

        p1=P1.first;

        v1=p1.first;
        c1=p1.second;
        c2=P1.second;

        //cout<<"here c2 : "<<c2<<endl;

        if(c2==0)
        {
            for(i=0;i<m;i++)
            {
                if(reach[v1[0]][i]==1)
                {
                   // cout<<"i : "<<i<<endl;
                    v2=v1;
                    v2[0]=i;
                    p2.first=v2;

                   /* for(j=0;j<n;j++)
                        cout<<v2[j]<<" ";
                    cout<<endl;
                    cout<<"again c2:"<<c2<<endl;*/

                    if(is_sorted(v2.begin(),v2.end()))
                    {
                        return 1;
                    }

                    if(v1[0]!=i)
                    {
                        p2.second=1;
                    }
                    else
                    {
                        p2.second=0;
                    }
                    P2.first=p2;
                    P2.second=1;
                    q.push(P2);

                }

            }
        }
        else
        {
             for(i=0;i<m;i++)
            {
                if(reach[v1[c2]][i]==1&&v1[c2-1]<=i)
                {
                    //cout<<"i : "<<i<<endl;

                    v2=v1;
                    v2[c2]=i;
                    p2.first=v2;

                    /*for(j=0;j<n;j++)
                        cout<<v2[j]<<" ";
                    cout<<endl;
                    cout<<"again c2:"<<c2<<endl;*/

                    if(is_sorted(v2.begin(),v2.end()))
                    {
                        return c1+1;
                    }

                    if(v1[c2]!=i)
                    {
                        p2.second=c1+1;
                    }
                    else
                    {
                        p2.second=c1;
                    }
                    P2.first=p2;
                    P2.second=c2+1;
                    q.push(P2);

                }

            }
        }

    }


    return -1;
}

int main()
{
    int test,i,j,k;
    int temp1,temp2;
    int ans1,ans2;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        queue< pair<pair< vector<int> ,int>,int> > q1;
        arr.clear();
        swap(q,q1);
        v1.clear();
        v2.clear();

        memset(graph,0,sizeof(graph));
        memset(reach,0,sizeof(reach));

        scanf("%d%d%d",&m,&k,&n);

        for(j=0;j<k;j++)
        {
            scanf("%d%d",&temp1,&temp2);

            temp1--;
            temp2--;

            graph[temp1][temp2]=1;
            graph[temp2][temp1]=1;
            graph[temp1][temp1]=1;
            graph[temp2][temp2]=1;
        }

        for(j=0;j<n;j++)
        {
            //cout<<"here"<<endl;
            scanf("%d",&temp1);

            temp1--;

            arr.push_back(temp1);
        }

        if(is_sorted(arr.begin(),arr.end()))
        {
            printf("0\n");
            continue;
        }

        find_r();

        ans1=solve();

        queue< pair<pair< vector<int> ,int>,int> > q2;
        swap(q,q2);
        v1.clear();
        v2.clear();

        ans2=solve2();

        if(ans1<0)
        {
            printf("%d\n",ans2);
        }
        else if(ans2<0)
        {
            printf("%d\n",ans1);
        }
        else
        {
            printf("%d\n",min2(ans1,ans2));
        }




    }

    return 0;
}















