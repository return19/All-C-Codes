#include<bits/stdc++.h>
using namespace std;

vector<long long> p;
long long s[1010000];

void sieve()
{
    long long i,j,k;
    s[0]=s[1]=1;

    for(i=2;i<34000;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<34000;j+=i){
                s[j]=1;
            }
        }
    }

    /*for(i=0;i<10;i++)
        cout<<p[i]<<" ";
    cout<<endl;*/
}

int main()
{
    ios::sync_with_stdio(false);
    long long i,j,k;
    long long test,t;
    long long x,y;

   // sieve();

    //scanf("%d",&test);
    cin>>test;

    for(t=0;t<test;t++)
    {
       // scanf("%d%d",&x,&y);
       cin>>x>>y;
        long long ans=0;

        for(i=0;i<=y-x;i++)
            s[i]=0;

        for(i=2;i*i<=y;i++){
            long long l = x/(i*i);

            if(l*i*i < x)
                l++;

            while(l*i*i <= y){
                    s[l*i*i - x]=1;
                l++;
                //cout<<l*i*i<<" "<<l<<" "<<y<<endl;
            }
        }

    //    for(i=x;i<=y;i++)
      //      cout<<i<<" "<<s[i-x]<<endl;

        for(i=0;i<=y-x;i++)
            if(!s[i])
                ans++;

        cout<<ans<<endl;
    }
    return 0;
}
















