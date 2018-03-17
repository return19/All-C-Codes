#include<bits/stdc++.h>
using namespace std;

int arr[1010000];
vector<int> jump[1010000];
int n;
map<int,int> ix;
int mx;
long long M = 1e9 + 7;
long long memo[1010000];
long long p2[1010000];

int main()
{
    int test,t;
    int i,j,k;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        mx = 0;
        scanf("%d",&n);

        p2[0]=1;

        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            memo[arr[i]]=0;
            if(i>0){
                p2[i] = (p2[i-1]*2)%M;
            }

            mx = max(mx,arr[i]);
        }
        sort(arr,arr+n);
        for(i=0;i<n;i++){
            int sq = sqrt(arr[i])+2;
            for(j=0;j<i && arr[j]<=sq;j++){
                if(arr[i]%arr[j]==0)
                    memo[arr[j]]++;
            }
        }
        long long ans=0;
        for(i=0;i<n;i++){
            ans = (ans + p2[memo[arr[i]]])%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}











