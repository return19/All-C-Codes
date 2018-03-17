#include<bits/stdc++.h>
using namespace std;

long long X=43;
long long m1=1000000007;
long long m2=3216547813;

map< pair<long long,long long>,long long> memo;
vector<long long> ans;

int main()
{
    long long i,j,k;
    long long n;
    scanf("%lld",&n);

    if(n==1)
    {
        printf("0\n");
        return 0;
    }

    for(i=2;i<=n;i++)
    {
        long long hsh1=0,hsh2=0;
        for(j=0;j<ans.size();j++)
        {
            long long t=0;
            if(i%ans[j]==0){
                t=1;
            }
            if(t==1){
                hsh1=(hsh1*X + X*ans[j])%m1;
                hsh2=(hsh2*X + X*ans[j])%m2;
            }
        }

      //  cout<<hsh1<<" "<<hsh2<<" "<<memo[make_pair(hsh1,hsh2)]<<endl;

        if((hsh1==0 && hsh2==0) || (memo[make_pair(hsh1,hsh2)]==1)){
            ans.push_back(i);
            //cout<<i<<" : "<<(i*X)%m1<<" "<<(i*X)%m2<<endl;
            memo[make_pair((hsh1*X + i*X)%m1,(hsh2*X + i*X)%m2)]=1;
        }
        else
        {
            memo[make_pair(hsh1,hsh2)]=1;
        }
    }
    printf("%lld\n",ans.size());
    for(i=0;i<ans.size();i++)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}

