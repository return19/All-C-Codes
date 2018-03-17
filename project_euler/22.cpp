#include<bits/stdc++.h>
using namespace std;

vector<string> arr;
map<string,int> ans;
int main()
{
    int i,j,k;
    int n;
    int q;
    string s;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        cin>>s;
        arr.push_back(s);
    }

    sort(arr.begin(),arr.end());

    for(i=0;i<n;i++){
        int sz = arr[i].length();
        int res=0;
        for(j=0;j<sz;j++){
            res += arr[i][j] - 'A' + 1;
        }
        ans[arr[i]] = res*(i+1);
    }

    scanf("%d",&q);
    for(i=0;i<q;i++){
        cin>>s;
        printf("%d\n",ans[s]);
    }

    return 0;
}













