#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    i=0;
    while(i<n && arr[i]==0)
        i++;
    int ans=0;
    for(;i<n;i++)
    {
        if(arr[i]==0 &&(i+1>=n || arr[i+1]==0))
        {
            while(i<n && arr[i]==0)
                i++;
            i--;
        }
        else
            ans++;
    }

    printf("%d\n",ans);
    return 0;
}
