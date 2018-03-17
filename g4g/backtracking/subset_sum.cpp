#include<bits/stdc++.h>
using namespace std;

int arr[110];

vector<int> v;

int cum_sum[110];

void printSub(int arr[],int n,int idx,int sum,vector<int> &v)
{
    if(sum<0)
        return;

    if(sum==0)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;

        return;
    }

    if(idx==n+1)
        return;

    if(cum_sum[n]-cum_sum[idx-1]<sum)
        return;

    printSub(arr,n,idx+1,sum,v);

    v.push_back(arr[idx]);

    printSub(arr,n,idx+1,sum-arr[idx],v);

    v.pop_back();

}

int main()
{
    int i,j,k;
    int n;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>arr[i];

    cum_sum[0]=0;

    for(i=1;i<=n;i++)
        cum_sum[i] = cum_sum[i-1] + arr[i];

    /*for(i=1;i<=n;i++)
        cout<<cum_sum[i]<<" ";
    cout<<endl;*/

    int sum;
    cin>>sum;

    printSub(arr,n,1,sum,v);

    return 0;
}
