#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

set< pair< pair<int,int>, pair<int,int> > > s; //h,tower,coin
set< pair< pair<int,int>, pair<int,int> > >::iterator it;
int n;

vector< pair<int,int> > layers;

int val[1010000];
int mxh[1010000];

int main()
{
    int i,j,k;
    int x,y,z;
    int h;
    int sum=0;
    int mx=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        h=0;
        for(j=0;j<k;j++){
            scanf("%d%d",&x,&y);
            if(!j){
                val[i] = y;
                sum+=y;
            }
            s.insert(mp(mp(h,1),mp(i,y)));
            mxh[i]= h;
            h += x;
            mx = max(mx,h);
        }
        s.insert(mp(mp(h,0),mp(i,0)));
    }
    cout<<"*"<<endl;
    for(it=s.begin();it!=s.end();it++){
        cout<<(*it).ft.ft<<" "<<(*it).sd.ft<<endl;
    }

    int cur=0;

    while(!s.empty()){
        int mns=0;
        it = s.begin();
        pair<pair<int,int>,pair<int,int > > p =*it;
        s.erase(p);

        if(p.ft.sd == 0){
            sum -= val[p.sd.ft];
            continue;
        }

        cout<<"*"<<sum<<" "<<p.sd.sd<<endl;

        layers.push_back(mp(0,sum + p.sd.sd - val[p.sd.ft]));
       // cout<<val[p.sd.ft]<<" "<<p.sd.sd<<endl;
       // if(mxh[p.sd.ft] == p.ft)
         //   mns += p.sd.sd;

        sum = sum + p.sd.sd - val[p.sd.ft];
        val[p.sd.ft] = p.sd.sd;
       // cout<<sum<<endl;
        int ln = layers.size();
        ln--;
        if(ln-1>=0){
            layers[ln-1].ft = p.ft.ft - cur;
            cur = layers[ln-1].ft;
        }
        while(!s.empty()){
            it = s.begin();
            p = *it;
            if(p.ft.ft != cur)
                break;
            s.erase(p);
           // cout<<"*1"<<sum<<" "<<p.sd.sd<<endl;
            layers[ln].sd += (p.sd.sd - val[p.sd.ft]);
            val[p.sd.ft] = p.sd.sd;

          //  if(mxh[p.sd.ft] == p.ft)
            //    mns += p.sd.sd;
        }
       // sum-= mns;
    }

    for(i=0;i<layers.size();i++){
        cout<<layers[i].ft<<" "<<layers[i].sd<<endl;
    }
    return 0;
}












