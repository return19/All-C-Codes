#include<bits/stdc++.h>
using namespace std;

int n,m;
double arr[101000];

bool check(double x){
    int i,j,k;
    int ans=0;
    for(i=0;i<n;i++){
        ans = ans + floor((arr[i]/x));
    }
    if(ans>=m)
        return true;
    return false;
}

int main()
{
    freopen("input00.txt","r",stdin);
    int i,j,k;
    double ed=0;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        scanf("%lf",&arr[i]);
        ed = max(ed,arr[i]);
    }

    double st=0;

    while(ed-st>=0.0001L){
        double mid = st + (ed-st)/2;
        if(check(mid)){
            st = mid;
        } else{
            ed = mid;
        }
    }

    printf("%.6lf\n",st);


    return 0;
}
