#include<bits/stdc++.h>
using namespace std;

long long arr[51][101000];
long long vis[5001000];
long long ans[51];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=1;i<=50;i++){
        arr[i][0] = i;
        long long c=0;
        for(j=1;j<n;j++){
            arr[i][j] = arr[i][j-1] + i;
            if(vis[arr[i][j]]==0)
                c++;
            vis[arr[i][j]]=1;
        }
       // cout<<i<<endl;
        ans[i]=c;
    }

   /* for(i=1;i<=5;i++){
        for(j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<" -> "<<ans[i];
        cout<<endl;
    }*/

   // cout<<"here"<<endl;

    long long res=0;

    for(i=0;i<=n;i++)
        vis[i]=0;

    for(i=2;i<=n;i++){
        if(!vis[i]){
     //       cout<<i<<endl;
            long long temp = i;
            long long c=1;
            while(temp<=n){
                vis[temp]=1;
                res += ans[c];
                c++;
                temp = temp*i;
                //cout<<i<<" "<<c<<endl;
            }
            //cout<<endl;
        }
    }

    printf("%lld\n",res);
    return 0;
}
