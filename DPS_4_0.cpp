#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000


int arr[10010][10010];

int n;

int fw()
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
}

int main()
{
    int u,v,i,j,k,m,q,temp,x,y,z;

    scanf("%d%d%d",&n,&m,&k);

      for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                arr[i][j]=0;
            else
                arr[i][j]=MAX;
        }
    }

    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        x--;
        z--;
        arr[x][y]=z;
        arr[y][x]=z;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    scanf("%d",&q);
    fw();
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&u,&v);
        if(arr[u-1][v-1]<=k)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
