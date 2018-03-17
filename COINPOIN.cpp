#include<bits/stdc++.h>
using namespace std;

int graph[110][110];

int main()
{
    int test,i,j,k;
    int n,m;
    int x,y;
    int count1;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        memset(graph,0,sizeof(graph));

        scanf("%d%d",&n,&m);

        for(j=0;j<m;j++)
        {
            scanf("%d%d",&x,&y);

            x--;
            y--;

            graph[x][y]=1;
            graph[y][x]=1;
        }

        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(j==k)
                    continue;

                if(graph[j][k]==0)
                    count1++;
            }
        }

        count1=count1/2;

        if(n==1)
        {
            printf("1\n");
        }
        else if(n==2)
        {
            if(count1==0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(n==3)
        {
            if(count1==0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }

        }
        else if(n==4)
        {
            if(count1==0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }

        }
        else if(n==5)
        {
            if(count1==1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }

        }

    }

    return 0;
}
