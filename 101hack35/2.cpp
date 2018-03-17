#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long n;

long long kval[101000];

vector< pair<long long,long long> > v[101000];
long long vis[101000];

pair<long long,long long> dfs(long long x)
{
    vis[x]=1;
    long long chk=0;
    long long i,j,k;
    pair<long long,long long> ans,temp;
    ans.ft=ans.sd=0;
    long long mx=0;

    for(i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i].ft])
        {
            temp=dfs(v[x][i].ft);

            if(temp.ft==-1)
                continue;

            if(mx<=temp.sd + v[x][i].sd)
            {
                mx=v[x][i].sd + temp.sd;
                ans.ft=temp.ft;
                ans.sd = mx;
                chk=1;
            }
        }
    }

    if(chk)
    {
        return ans;
    }else{
        if(kval[x])
        {
            ans.ft=x;
            ans.sd=0;
            return ans;
        }

        ans.ft=-1;
        ans.sd=-1;
        return ans;
    }

}

pair<long long,long long> dfs1(long long x)
{
    vis[x]=1;
    long long i,j,k;

    pair<long long,long long> ans,temp;
    ans.ft=ans.sd=0;
    long long sum=0;
    long long chk=0;

    for(i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i].ft])
        {
            temp=dfs1(v[x][i].ft);

            if(temp.ft==-1)
                continue;

            temp.ft += v[x][i].sd;

            chk=1;

            sum += temp.ft + temp.sd;

            if(ans.ft<temp.ft)
            {
                ans=temp;
            }
        }
    }

    if(chk==0)
    {
        if(kval[x])
        {
            return ans;
        }else{
            ans.ft=ans.sd=-1;
            return ans;
        }
    }

    sum =sum - ans.ft;
    return mp(ans.ft,sum);
}


int main()
{
    long long i,j,k;
    long long x,y,z;
    long long bg;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<k;i++)
    {
        scanf("%lld",&x);
        x--;
        kval[x]=1;
        bg=x;
    }

    for(i=0;i<n-1;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        x--;
        y--;
        v[x].push_back(mp(y,z));
        v[y].push_back(mp(x,z));
    }

    for(i=0;i<n;i++)
        vis[i]=0;
    pair<long long,long long> st=dfs(bg);

    //cout<<st.ft<<" "<<st.sd<<endl;

    for(i=0;i<n;i++)
        vis[i]=0;

    pair<long long,long long> ans=dfs1(st.ft);

    printf("%lld\n",ans.ft + 2*ans.sd);


    return 0;
}
















