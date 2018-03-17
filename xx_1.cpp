#include<bits/stdc++.h>
using namespace std;

map<long long,long long> b,g;
pair<long long,long long> p;
map<pair<long long,long long>,long long > memo;

int main()
{
    long long n,m,i,j,k,b_count=0,g_count=0;
    long long b_h,g_h;
    long long temp;

    //scanf("%lld%lld",&n,&m);
    cin>>n>>m;
    //scanf("%lld",&b_h);
    cin>>b_h;
    b_count=b_h;
    for(i=0;i<b_h;i++)
    {
        //scanf("%lld",&temp);
        cin>>temp;
        b[temp]=1;
    }
    //scanf("%lld",&g_h);
    cin>>g_h;
    g_count=g_h;
    for(i=0;i<g_h;i++)
    {
        //scanf("%lld",&temp);
        cin>>temp;
        g[temp]=1;
    }
    p.first=0;
    p.second=0;
    i=0;

    while(!memo[p]||(memo[p]&&(b[i%n]&&g[i%m])))
    {
        if(b[i%n]&&!g[i%m]){
            g_count++;
            g[i%n]=1;
        }
        else if(!b[i%n]&&g[i%m]){
            b_count++;
            b[i%m]=1;
        }

        if(b_count==n&&g_count==m)
        {
            //printf("Yes\n");
            cout<<"Yes\n";
            return 0;
        }

        memo[p]=1;
        i++;

        p.first=i%n;
        p.second=i%m;

        //cout<<i%n<<" "<<i%m<<"   "<<b[i%n]<<" "<<g[i%m]<<endl;
    }

    //printf("No\n");
    cout<<"No\n";
    return 0;
}
