#include<bits/stdc++.h>
using namespace std;


unordered_map<int,int> memo;

int arr[4010][5];

int main()
{
    int n,i,j,k;
    int ans=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            memo[arr[i][0]+arr[j][1]]++;
        }
    }

    ans=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(memo[-1*(arr[i][2]+arr[j][3])])
            {
                ans=ans+memo[-1*(arr[i][2]+arr[j][3])];
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}








