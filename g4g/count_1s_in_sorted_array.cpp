#include<bits/stdc++.h>
using namespace std;

int arr[110000];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int i,j,k;

    int n;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int high=upper_bound(arr,arr+n,1,cmp)-arr;

    if(arr[high-1]==1)
        cout<<high<<endl;
        else
            cout<<0<<endl;

    return 0;
}
