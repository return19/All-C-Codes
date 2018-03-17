#include<bits/stdc++.h>
using namespace std;

map<string,int> memo;
map<string,int>::iterator it;

map<string,int> all;
map<int,string> latest;

string a,b;

int main()
{
    int n,i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        cin>>a>>b;

        if(all.find(a)==all.end())
        {
            memo[a]=i;
            all[a]=i;
            all[b]=i;
            latest[i]=b;
        }
        else
        {
            int num=all[a];
            all[b]=num;
            latest[num]=b;
        }
    }
    cout<<memo.size()<<endl;
    for(it=memo.begin();it!=memo.end();it++)
    {
        cout<<it->first<<" "<<latest[it->second]<<endl;
    }

    return 0;
}
