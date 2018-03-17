#include<bits/stdc++.h>
using namespace std;

long long n,m;

long long graph[410][410];
long long fw[410][410];

void fw1()
{
    long long i,j,k;

    for(k=0;k<n;k++)
    {

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(fw[i][k]!=99999999999999&&fw[k][j]!=99999999999999&&fw[i][k]+fw[k][j]<fw[i][j])
                {
                    fw[i][j]=fw[i][k]+fw[k][j];
                }
            }
        }

    }
}

int main()
{
    long long i,j,k;
    long long x,y,w;
    long long q,ans;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++){

            if(i==j)
            {
                graph[i][j]=0;

                fw[i][j]=0;
                continue;
            }
            graph[i][j]=-1;
            fw[i][j]=99999999999999;

        }
    }

    for(i=0;i<m;i++)
    {


        scanf("%lld%lld%lld",&x,&y,&w);

        x--;
        y--;

        graph[x][y]=w;
        fw[x][y]=w;
    }

    fw1();



    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {


        scanf("%lld%lld",&x,&y);


        ans=fw[x-1][y-1];

        if(ans==99999999999999)
        {
            cout<<-1<<endl;
            continue;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
