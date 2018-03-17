#include<bits/stdc++.h>
using namespace std;

long long s[1010000];
vector<long long> p;
void sieve(){
    long long i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=100010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=100010;j+=i)
                s[j]=1;
        }
    }
}

long long dsum[101000];
map<long long,long long> memo;
long long is[101000];
long long ans[101000];

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;

    sieve();
    for(i=1;i<=100010;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                dsum[i] += j + (i/j);
                if(j==i/j)
                    dsum[i]-=j;
            }
        }
        dsum[i]++;
        //cout<<i<<" "<<dsum[i]<<endl;
    }

    for(i=1;i<=100010;i++)
    {
        if(i==dsum[dsum[i]] && (i!=dsum[i])){
            is[i]=1;
            is[dsum[i]]=1;
        }
        ans[i] = ans[i-1];
        if(is[i])
            ans[i] += i;
    }

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
