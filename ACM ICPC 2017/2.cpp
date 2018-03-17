#include<bits/stdc++.h>
using namespace std;

int arr[1010000];
vector<int> jump[1010000];
int n;
map<int,int> ix;
int mx;
long long M = 1e9 + 7;
long long memo[1010000];
/*
long long solve(long long idx){
    long long ans=1;
    long long i,j;
    if(jump[arr[idx]].size()==0)
        return 1;

    if(memo[idx]!=-1)
        return memo[idx];

    for(i=0;i<jump[arr[idx]].size();i++){
        ans = (ans + solve(jump[arr[idx]][i]))%M;
    }
    return memo[idx] = ans;
}
*/
int main()
{
    int test,t;
    int i,j,k;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        ix.clear();
        mx = 0;
        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            mx = max(mx,arr[i]);
        }
        sort(arr,arr+n);
        for(i=0;i<n;i++)
            ix[arr[i]]= i;

        for(i=0;i<n;i++){
            jump[arr[i]].resize(0);
            int tmp = arr[i]*2;
            while(tmp<=mx){
                if(ix.find(tmp)!=ix.end())
                    jump[arr[i]].push_back(ix[tmp]);
                tmp+=arr[i];
            }
        }

        /*for(i=0;i<n;i++){
                cout<<"*"<<jump[arr[i]].size()<<endl;
            for(j=0;j<jump[arr[i]].size();j++)
                cout<<jump[arr[i]][j]<<" ";
            cout<<endl;
        }*/

        long long ans = 0;

        for(i=n-1;i>=0;i--){
            if(jump[arr[i]].size()==0)
                memo[i]=1;
            else {
                memo[i]=1;
                for(j=0;j<jump[arr[i]].size();j++){
                    memo[i] = (memo[i] + memo[jump[arr[i]][j]])%M;
                }
            }
        }

        for(i=0;i<n;i++){
            ans = (ans + memo[i])%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}










