#include<bits/stdc++.h>
using namespace std;

vector<string> v;

long long cost(char a,char b)
{
    long long i,j,k;
    long long ans=0;

    for(i=0;i<v.size();i++)
    {
        long long sz=v[i].length(),f=0;
        for(j=0;j<sz;j++)
        {
            if(v[i][j]!=a && v[i][j]!=b)
            {
                f=1;
                break;
            }
        }

        if(f==0)
            ans+=v[i].length();
    }
    return ans;
}

int main()
{
    long long i,j,k;
    long long n;
    string s;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }

    long long ans=0;

    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            ans=max(ans,cost('a'+i,'a'+j));
        }
    }

    printf("%lld\n",ans);

    return 0;
}











