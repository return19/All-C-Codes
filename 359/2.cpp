#include<bits/stdc++.h>
using namespace std;

int arr[110];

vector< pair<int,int> > ans;

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                ans.push_back(make_pair(j,j+1));
                swap(arr[j],arr[j+1]);
            }
        }
    }

    /*for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    for(i=0;i<ans.size();i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    return 0;
}

