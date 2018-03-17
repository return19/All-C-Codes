#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int main()
{
    int n;
    int i,j,k;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>k;
        arr.push_back(k);
    }

    sort(arr.begin(),arr.end());

    int q;

    cin>>q;

    for(i=0;i<q;i++)
    {
        int x;

        cin>>x;

        cout<<lower_bound(arr.begin(),arr.end(),x)-arr.begin()<<endl;
    }

    return 0;
}
