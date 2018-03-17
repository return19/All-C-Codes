#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int dp[110];
int cnt[110];
int n;

vector< vector<int> > v;

vector<int> vans;
int ans11,ans22;

void lis(vector<int> &arr){
    int i,j,k;

    for(i=0;i<n;i++)
    {
        dp[i]=1;
        cnt[i]=1;
    }

    for(i=0;i<n;i++){
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i]){
                if(dp[j]+1==dp[i])
                    cnt[i]++;
                else if(dp[j]+1>dp[i]){
                    cnt[i]=1;
                    dp[i]=dp[j]+1;
                }
            }
        }
    }

   /* for(i=0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;

    for(i=0;i<n;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;*/

    int ans=0;
    int c=0;
    for(i=0;i<n;i++){
        if(ans<dp[i]){
            ans=dp[i];
            c=cnt[i];
        }else if(ans==dp[i]){
            c+=cnt[i];
        }
    }
   /* for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<" : ";
    cout<<ans<<" "<<c<<endl;*/

    if(c>ans22){
        ans22=c;
        ans11=ans;
        vans=arr;
    }
}

void permute(vector<int> &a, int l, int r)
{
   int i;
   if (l == r)
     v.push_back(a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a[l]), (a[i]));
          permute(a, l+1, r);
          swap((a[l]), (a[i])); //backtrack
       }
   }
}

int main()
{
    int i,j,k;

    for(n=1;n<=10;n++){

    v.resize(0);
    arr.resize(0);

    for(i=0;i<n;i++)
        arr.push_back(i);
    permute(arr,0,n-1);

    for(i=0;i<v.size();i++)
        lis(v[i]);

    for(i=0;i<n;i++)
        cout<<vans[i]<<" ";
    cout<<endl;
    cout<<ans11<<" "<<ans22<<endl;
    }
    return 0;
}
