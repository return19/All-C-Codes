#include<bits/stdc++.h>
using namespace std;

int arr[1010000];

int main()
{
    freopen("input00.txt","r",stdin);
    //freopen("output00.txt","w",stdout);
    int i,j,k;
    int n;
    int x;
    scanf("%d%d",&n,&k);
    cout<<n<<k<<endl;

    for(j=0;j<3;j++){
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(j==0){
                arr[i]=x;
            } else
                arr[i] = min(arr[i],x);
        }
    }

    sort(arr,arr+n);
    long long ans=0;
    for(i=0;i<k;i++){
        ans = ans + arr[i];
    }
    printf("%lld\n",ans);
    return 0;
}
