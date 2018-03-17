#include<bits/stdc++.h>
using namespace std;

long long n,m;
long double arr[1010000];

bool check(long double x){
    long long i,j,k;
    long long ans=0;
    for(i=0;i<n;i++){
        ans = ans + floor((arr[i]/x));
    }
    if(ans>=m)
        return true;
    return false;
}

int main()
{
    freopen("input05.txt","r",stdin);
    long long i,j,k;
    long double ed=0;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++){
       // scanf("%lf",&arr[i]);
       cin>>arr[i];
        ed = max(ed,arr[i]);
    }

    long double st=0;

    while(ed-st>0.001){
      //  cout<<ed-st<<endl;
        long double mid = st + (ed-st)/2;
        if(check(mid)){
            st = mid;
        } else{
            ed = mid;
        }
    }
    //cout<<st<<endl;
    cout<<setprecision(20)<<st<<endl;
   // printf("%Lf\n",st);


    return 0;
}
