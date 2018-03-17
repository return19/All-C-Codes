#include<bits/stdc++.h>
using namespace std;

int arr[110];

unordered_map<int,int> memo;

int main()
{
    int n,i,j,k;
    int ans=0;


    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                memo[arr[i]*arr[j]+arr[k]]++;
            }
        }
    }


    ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[i]!=0)
                {
                    if(memo[arr[i]*(arr[j]+arr[k])])
                        ans=ans+memo[arr[i]*(arr[j]+arr[k])];
                }
            }
        }
    }

    printf("%d\n",ans);



    return 0;
}







