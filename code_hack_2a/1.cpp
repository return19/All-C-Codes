#include<bits/stdc++.h>
using namespace std;

int arr[110][110];
int dp[110][110];

int main()
{
    int test,i,j,k;
    int n;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(arr,0,sizeof(arr));

        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }

        for(j=1;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(k==0)
                {
                    if(arr[j-1][k]&&arr[j][k])
                        arr[j][k]=arr[j-1][k]+1;
                }
                else
                {
                    if(arr[j-1][k]&&arr[j][k])
                        arr[j][k]=arr[j-1][k]+1;
                        else if(arr[j][k-1]&&arr[j][k])
                            arr[j][k]=arr[j][k-1];
                }
            }
        }

        if(arr[n-1][n-1]==n)
        {
            printf("POSSIBLE\n");
        }
        else
        {
            printf("NOT POSSIBLE\n");
        }


    }

    return 0;
}









