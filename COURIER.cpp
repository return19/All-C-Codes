#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000

long dist[10010][10010];
long pack[110][3];
long v,PACK=-1;

void init()
{
    long i,j;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=MAX;
            }

        }
    }
}
void floyd_warshall()
{


    long i,j,k;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            for(k=0;k<v;k++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    long i,j,k,start,last,w,test,crs,edges,home,sum;
    long min,index,count;
    //cin>>test;
    scanf("%ld",&test);
    for(i=0;i<test;i++)
    {
        sum=0;
        PACK=-1;
        //cin>>v;
        //cin>>edges;
        //cin>>home;
        scanf("%ld",&v);
        scanf("%ld",&edges);
        scanf("%ld",&home);
        init();
        for(j=0;j<edges;j++)
        {
            /*cin>>start;
            cin>>last;
            cin>>w;*/
            scanf("%ld",&start);
            scanf("%ld",&last);
            scanf("%ld",&w);
            dist[start-1][last-1]=w;
            dist[last-1][start-1]=w;
        }
        floyd_warshall();

        //cin>>crs;
        scanf("%ld",&crs);
        for(j=0;j<crs;j++)
        {
            /*cin>>start;
            cin>>last;
            cin>>w;*/
            scanf("%ld",&start);
            scanf("%ld",&last);
            scanf("%ld",&w);
            pack[++PACK][0]=start-1;
            pack[PACK][1]=last-1;
            pack[PACK][2]=w;
        }

        last=home-1;
        for(;;)
        {
            min=MAX;
            count=0;
            start=last;
            for(k=0;k<crs;k++)
            {
                if(pack[k][2]&&min>dist[start][pack[k][0]])
                {
                    min=dist[start][pack[k][0]];
                    last=pack[k][0];
                    index=k;
                }
            }
            if(min==MAX)
                break;

            pack[index][2]=(pack[index][2])-1;
            sum=sum+min;
            //cout<<min<<" + ";
            start=pack[index][0];
            last=pack[index][1];
            sum=sum+dist[start][last];

            //cout<<dist[start][last]<<" + ";

        }
        //cout<<dist[start][home-1]<<endl;
        sum=sum+dist[start][home-1];
       // cout<<dist[start][home-1]<<endl;
        //cout<<sum<<endl;
        printf("%ld\n",sum);
    }

    return 0;
}



















