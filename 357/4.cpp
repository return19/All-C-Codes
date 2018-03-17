#include<bits/stdc++.h>
using namespace std;

map<int,int> val;
int par[101000];
int nonroot[101000],chain[101000];
int lat[101000],des[101000];

set< pair<int,int> > s;
set< pair<int,int> >::iterator it;

vector<int> ans;

int main()
{
    int i,j,k;
    int n,m;
    int x,y;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        par[y]=x;
        nonroot[x]=1;
    }

    for(i=1;i<=n;i++)
        scanf("%d",&des[i]);

    int c=0;
    for(i=1;i<=n;i++){
        if(nonroot[i]==0)
        {
            c++;
            s.insert(make_pair(c,i));
            j=i;
            val[j]=1;   int x=1;
            chain[j]=c;
            lat[c]=des[j];
            while(par[j])
            {
                j=par[j];
                x++;
                val[j]=x;
                chain[j]=c;
            }
        }
    }


    while(!s.empty())
    {
        it=s.begin();
        int cno=it->first;
        int x=it->second;

        if(val[x]<=val[lat[chain[x]]] && des[x]!=lat[chain[x]])
        {
            printf("-1\n");
            return 0;
        }

        if(val[x]<=val[lat[chain[x]]]){
            if(par[x])
                s.insert(make_pair(cno+1,par[x]));
        }else{
            lat[chain[x]]=des[x];
            if(par[x])
                s.insert(make_pair(cno+1,par[x]));
        }
        s.erase(*it);
         ans.push_back(lat[chain[x]]);
    }

    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    return 0;
}

















