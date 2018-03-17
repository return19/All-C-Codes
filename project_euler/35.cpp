#include<bits/stdc++.h>
using namespace std;
#define N 1000010
long long s[N];

void sieve(){
    long long i,j,k;
    long long c=0;
    s[0]=s[1]=1;
    for(i=2;i<=N;i++){
        if(!s[i]){
                c++;
            for(j=i*2;j<=N;j+=i){
                s[j]=1;
            }
        }
    }
   // cout<<c<<endl;
}

long long eval(vector<long long> &a){
    long long ans=0;
    for(long long i=0;i<a.size();i++)
        ans = ans*10 + a[i];
    return ans;
}

long long check(long long x){
    if(s[x])    return 0;
    vector<long long> num;
    long long t=x;
    while(t){
        num.push_back(t%10);
        t/=10;
    }

    long long i,j;
    for(i=0,j=num.size()-1;i<j;i++,j--)
        swap(num[i],num[j]);

    rotate(num.begin(),num.begin()+num.size()-1,num.end());
    //cout<<x<<" ";
    //for(i=0;i<num.size();i++)
      //  cout<<num[i];
    //cout<<endl;
    long long temp = eval(num);
    while(temp!=x){
        if(s[temp]) return 0;
        rotate(num.begin(),num.begin()+num.size()-1,num.end());
        temp = eval(num);
    }
    return 1;
}

int main()
{
    long long i,j,k;
    long long n;
    sieve();
    scanf("%lld",&n);

    long long ans=0;
    for(i=2;i<n;i++){
        if(check(i))
            ans += i;
    }
    printf("%lld\n",ans);
    return 0;
}












