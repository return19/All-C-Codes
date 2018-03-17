#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<int,int> > g[101000];
int n,c;
int vis[101000];

void rmDuplicate(vector<int> &vec){
    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}

pair< vector<int>,int> solve(int x,int y){
    int i,j,k;
    if(x==y){
        vector<int> res;
        return mp(res,1);
    }

    vis[x]=1;
    vector<int> res;
    int f=0;
    int ff=0;

    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i].ft]){
            pair<vector<int>,int> temp1 = solve(g[x][i].ft,y);
            if(temp1.sd==0){
                continue;
            }

            f=1;
            vector<int> temp = temp1.ft;

               /*  for(j=0;j<temp.size();j++)
                cout<<temp[j]<<" + ";
            cout<<endl;*/

            temp.push_back(g[x][i].sd);
            sort(temp.begin(),temp.end());
            rmDuplicate(temp);

           /* cout<<i<<" * "<<x<<endl;
            for(j=0;j<temp.size();j++)
                cout<<temp[j]<<" - ";
            cout<<endl;*/

            if(ff==0){
                res = temp;
                ff=1;
            }
            else
            {
                //cout<<"here "<<g[x][i].ft<<endl;
                vector<int> t;
                t.resize(max(res.size(),temp.size()));
                vector<int>::iterator it = set_intersection(res.begin(),res.end(),
                                                           temp.begin(),temp.end(),
                                                           t.begin());
                t.resize(it-t.begin());
                res=t;
            }
        }
    }
    /*for(j=0;j<res.size();j++)
                cout<<res[j]<<" ++ ";
            cout<<endl;*/
    vis[x]=0;
    return mp(res,f);
}

int main()
{
    int i,j,k;
    int x,y,z;
    int m;

    scanf("%d%d%d",&n,&m,&c);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        x--;    y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }

    int q;
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        pair< vector<int>,int> ans = solve(x,y);
        if(ans.sd==1){
            printf("%d\n",ans.ft.size());
        }
    }
    return 0;
}


















