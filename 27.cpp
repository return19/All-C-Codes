#include<bits/stdc++.h>
using namespace std;

int s[101000];
vector<int> p;

void sieve(){
    int i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=100010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=100010;j+=i){
                s[j]=1;
            }
        }
    }
}

int solve(int a,int b){
    int i,j,k;
    for(i=0;;i++){
        if(i*i + a*i + b <=0 || s[i*i + a*i + b])
            return i;
    }
}


int main(){
    int i,j,k;
    sieve();
    int n;

    scanf("%d",&n);

    int ans=0;
    pair<int,int> res;

    for(i=-n;i<=n;i++){
        for(j=0;p[j]<=n;j++){
            int temp = solve(i,p[j]);
            if(ans<temp){
                ans = max(ans,temp);
                res.first = i;
                res.second = p[j];
            }
        }
    }

    printf("%d %d\n",res.first,res.second);
   // printf("%d\n",ans);

    return 0;
}


























