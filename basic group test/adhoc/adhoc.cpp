#include<bits/stdc++.h>
using namespace std;
#define M 200005
int a[M];
int main() {
    //freopen("input07.txt","r",stdin);
   // freopen("output07.txt","w",stdout);
  int t;
  cin>>t;
  while(t--) {
     int n;
     cin>>n;
     for(int i=0;i<n;i++) {
        cin>>a[i];
     }
     int ind=0;
     while(a[ind]==1&&ind<n) {
        ind++;
     }
     int ans=0;
     int cnt=0;
     int time;
     for(int i=ind;i<n;i++) {
        if(a[i]==1) {
           if(cnt<=ans) {
              ans++;
           } else {
              ans=cnt;
           }
        } else {
          cnt++;
        }
     }
     cout<<ans<<endl;
  }
  return 0;
}
