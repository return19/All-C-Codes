#include<bits/stdc++.h>
using namespace std;

int rec[10100];
int ans[10100];
int ansval[10100];

int s[10100];
vector<int> p;

void sieve(){
    int i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=10010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=10010;j+=i){
                s[j]=1;
            }
        }
    }
}

map< int,int > memo;

int solve(int x){
    int i,j,k;
    memo.clear();
    int cur=1;
    while(cur<x){
        cur*=10;
    }
    int ans=0;
    while(memo.find(cur%x)==memo.end()){
        ans++;
        memo[cur%x]=ans;
        cur=cur%x;
        if(cur==0)
            return 0;
        while(cur<x)
            cur = cur*10;
    }
    return ans-memo[cur%x]+1;
}

int main()
{
    int i,j,k;
    sieve();
    for(i=1;i<=10000;i++){
        if(s[i]){
               // cout<<i<<endl;
            ansval[i] = ansval[i-1];
            ans[i] = ans[i-1];
            continue;
        }
        int temp = solve(i);
      //  cout<<i<<" "<<temp<<endl;
        if(ansval[i-1] > temp){
            ansval[i] = ansval[i-1];
            ans[i] = ans[i-1];
        } else {
            ansval[i] = temp;
            ans[i] = i;
        }
    }
    /*cout<<p.size()<<endl;
    for(i=0;i<p.size();i++){
        int temp = solve(p[i]);
    }
    cout<<"here"<<endl;*/

    int test,t;
    int n;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%d",&n);
        printf("%d\n",ans[n-1]);
        //cout<<ansval[n-1]<<endl;
    }

    return 0;
}
