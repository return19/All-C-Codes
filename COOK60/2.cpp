#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
    int test,i,j,k;
    int n;
    int m,x,y;
    int t;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(arr,0,sizeof(arr));

        scanf("%d%d%d",&m,&x,&y);

        x=x*y;

        for(j=0;j<m;j++)
        {
            scanf("%d",&t);
            int p=0;
            k=t;
            while(k>=1&&p<=x)
            {

                arr[k]=1;
                k--;
                p++;
            }

            k=t;
            p=0;

            while(k<=100&&p<=x)
            {
                arr[k]=1;
                k++;
                p++;
            }
        }
        int ans=0;
        for(j=1;j<=100;j++)
        {
            if(arr[j]==0)
            {
                ans++;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}

