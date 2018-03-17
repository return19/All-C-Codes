#include<bits/stdc++.h>
using namespace std;

int arr[101000];

map<int,int> memo;

map<int,int> ans;

int n,a,b;

int main()
{
    int i,j,k;

    scanf("%d%d%d",&n,&a,&b);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        memo[arr[i]]=1;
        ans[arr[i]]=0;
    }

   // sort(arr,arr+n);

    int s=0;

    if(a<b)
    {
        swap(a,b);
        s=1;
    }

    for(i=0;i<n;i++)
    {
        if(ans[arr[i]]!=0)
            continue;

        if(a>=arr[i] && memo[a-arr[i]]==1 && memo[arr[i]]==1){
            ans[arr[i]]=0;
            ans[a-arr[i]]=0;
            memo[arr[i]]=0;
            memo[a-arr[i]]=0;
        }
        else if(b>=arr[i] && memo[b-arr[i]]==1 && memo[arr[i]]==1){
            ans[arr[i]]=1;
            ans[b-arr[i]]=1;
            memo[b-arr[i]]=0;
            memo[arr[i]]=0;
        }
        else
        {
          /*  cout<<arr[i]<<" "<<a-arr[i]<<" "<<b-arr[i]<<endl;

            cout<<memo[a-arr[i]]<<" "<<memo[b-arr[i]]<<endl;

            cout<<ans[a-arr[i]]<<" "<<ans[b-arr[i]]<<endl;*/

            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(i=0;i<n;i++)
        if(s==0)
        printf("%d ",ans[arr[i]]);
    else
        printf("%d ",1-ans[arr[i]]);

    return 0;
}













