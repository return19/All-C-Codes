#include<bits/stdc++.h>
using namespace std;

int n;
//vector<int> b[200000];
int a[200000];
int ans[200000];
int v[200000];
int main()
{
	//freopen("input10.txt","r",stdin);
	//freopen("output10.txt","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i] = 100000000;
    }

    queue<int> q;

    ans[1] = 0;
    //v[1] = 1;
    q.push(1);

    while(!q.empty()){
        int p = q.front();
        q.pop();
        v[p] = 1;

        if(p-1>1 && v[p-1]==0 && ans[p-1]>(ans[p]+1)){
            ans[p-1] = ans[p] + 1;
            q.push(p-1);
        }

        if(p+1<=n && v[p+1]==0 && ans[p+1]>(ans[p]+1)){
            ans[p+1] = ans[p] + 1;
            q.push(p+1);
        }

        if(v[a[p]]==0 && ans[a[p]]>(ans[p]+1)){
            ans[a[p]] = ans[p] + 1;
            q.push(a[p]);
        }
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
