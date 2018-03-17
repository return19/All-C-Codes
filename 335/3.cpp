#include<bits/stdc++.h>
using namespace std;

int arr[101000];
int n;
int ans[101000];

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
        arr[i]--;

    int lis=0;

    for(i=0;i<n;i++)
    {
        ans[arr[i]]=ans[arr[i]-1]+1;
        lis=max(lis,ans[arr[i]]);
    }
  /*  for(i=0;i<n;i++)
        cout<<ans[arr[i]]<<" ";
        cout<<endl;

    cout<<lis<<endl;*/
    printf("%d\n",n-lis);

    return 0;
}
