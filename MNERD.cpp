#include<bits/stdc++.h>
using namespace std;

int arr[110][110];

int main()
{
    int n,m,i,j,k;

    scanf("%d%d",&n,&m);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            arr[i][j]=0;
        }
    }

    int x,y;

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        arr[x][y]=1;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

    int ans=0;
    int temp;

    for(i=1;i*i<=m;i++)
    {
        if(m%i==0)
        {
            x=i;
            y=m/i;

            for(j=1;j+x-1<=n;j++)
            {
                for(k=1;k+y-1<=n;k++)
                {
                    int t1=j+x-1,t2=k+y-1;

                    temp=arr[t1][t2] - arr[j-1][t2] - arr[t1][k-1] + arr[j-1][k-1];

                    //cout<<j<<" "<<k<<" : "<<t1<<" "<<t2<<" :: "<<temp<<endl;

                    ans=max(ans,temp);
                }
            }
        }
    }

    printf("%d\n",m-ans);

    return 0;
}









