#include<iostream>
#include<queue>
#include<cstdlib>
#include<utility>
#include<cstdio>
#include<cstring>
using namespace std;


int flag[10000];
int visited[10000];
int d[10000];
int gen_prime()
{
    int i,j,p;
    flag[0]=flag[1]=1;
    for(i=2;i<10000;i++)
    {
        if(flag[i]==0)
        {
            p=i*2;
            for(j=2;p<10000;p=i*j)
            {

                flag[p]=1;
                j++;
            }
        }
    }
}

int count_path(int start,int last)
{
    queue<int> q;
    char temp[10],temp2;
    int count=0,i,j,temp1,u;
    memset(visited,0,sizeof(visited));
    memset(d,0,sizeof(d));
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        sprintf(temp,"%d",u);


        for(i=0;i<4;i++)
        {
            temp2=temp[i];
            for(j=0;j<=9;j++)
            {
                if(i==0&&j==0)  continue;
                temp[i]=j+'0';
                temp1=atoi(temp);


                if(visited[temp1]==0&&flag[temp1]==0&&temp1!=u)
                {
                    q.push(temp1);
                    visited[temp1]=1;
                    d[temp1]=d[u]+1;
                    if(temp1==last)
                    {

                    return d[last];
                    }

                }
            }
            temp[i]=temp2;
        }

    }

    return -1;
}

int main()
{
    int test,last,i,j;
    int start;
    cin>>test;
    gen_prime();
    /*for(i=0;i<100;i++)
        cout<<i<<": "<<flag[i]<<endl;*/
    for(i=0;i<test;i++)
    {
        cin>>start;
        cin>>last;

        if(start==last)
            cout<<0<<endl;
        else if(count_path(start,last)==-1)
            cout<<"impossible"<<endl;
        else
            cout<<count_path(start,last)<<endl;

    }
    return 0;
}























