#include<bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> a;
vector<long long> b;
long long vis[7];

long long solve(long long idx,vector<long long> &v){
    if(idx==n+m){
        long long i,j,k;
        long long f=0;

      //  for(i=0;i<n+m;i++)
       //     cout<<v[i]<<" ";
       // cout<<endl;

        for(i=0;i<n;i++){
            if(v[i]>a[i])
                return 0;
            else if(v[i]<a[i])
            {
                f=1;
                break;
            }
        }
      //  cout<<"h1"<<endl;
        f=0;
        for(i=n;i<n+m;i++){
            if(v[i]>b[i-n])
                return 0;
            else if(v[i]<b[i-n]){
                f=1;
                break;
            }
        }
       // cout<<"h2"<<endl;
        for(i=0;i<7;i++)  vis[i]=0;

        for(i=0;i<n+m;i++)
        {
            if(vis[v[i]])   return 0;
            vis[v[i]]=1;
        }
        //cout<<":1"<<endl;
        return 1;
    }
    long long i;
    long long ans=0;
    for(i=0;i<7;i++){
        v.push_back(i);
        ans += solve(idx+1,v);
        v.pop_back();
    }

    return ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld",&n,&m);

    n--;
    m--;

    if(n!=0){
        while(n>=7){
            a.push_back(n%7);
            n/=7;
        }

        if(n)
            a.push_back(n);
    }else{
        a.push_back(0);
    }

    if(m!=0){
        while(m>=7){
            b.push_back(m%7);
            m/=7;
        }

        if(m)
            b.push_back(m);
    }else{
        b.push_back(0);
    }

    for(i=0,j=a.size()-1;i<j;i++,j--)
        swap(a[i],a[j]);

    for(i=0,j=b.size()-1;i<j;i++,j--)
        swap(b[i],b[j]);

    /*for(i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(i=0;i<b.size();i++)
        cout<<b[i]<<" ";
    cout<<endl;*/

   // cout<<a.size()<<" "<<b.size()<<endl;

    if(a.size() + b.size() >7){
        printf("0\n");
        return 0;
    }

    n=a.size();
    m=b.size();

    vector<long long> x;
    long long ans=solve(0,x);
    printf("%lld\n",ans);

    return 0;
}

