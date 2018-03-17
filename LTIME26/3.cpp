#include<bits/stdc++.h>
using namespace std;

long long arr[1010][1010];


int main()
{
    long long test,i,j,k;
    long long n;
    long long x,y;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {


        scanf("%lld%lld",&n,&k);

        if(k==1)
        {
            long long ans=n*n,x1,y1;

            scanf("%lld%lld",&x1,&y1);

            x=x1;   y=y1;

            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                ans--;
                x--;
                y--;
            }
            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                ans--;
                x++;
                y++;

            }

            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                ans--;
                x--;
                y++;

            }

            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                ans--;

                x++;
                y--;

            }

            ans=ans+3;

            printf("%lld\n",ans);

            continue;
        }




        long long t;
        for(j=1;j<=n;j++)
        {
            for(t=1;t<=n;t++)
            {
                arr[j][t]=0;
            }
        }

        for(j=0;j<k;j++)
        {
            long long x1,y1;
            scanf("%lld%lld",&x1,&y1);

            x=x1;   y=y1;

            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                arr[x][y]=1;
                x--;
                y--;
            }
            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                arr[x][y]=1;
                x++;
                y++;

            }

            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                arr[x][y]=1;
                x--;
                y++;

            }

            x=x1;   y=y1;
            while(x>=1&&x<=n&&y>=1&&y<=n)
            {
                arr[x][y]=1;

                x++;
                y--;

            }
        }

        //long long t;
        long long ans=0;

        for(j=1;j<=n;j++)
        {
            for(t=1;t<=n;t++)
            {
                if(arr[j][t]==0)
                    ans++;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}














