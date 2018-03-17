#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair< pair<long long,long long>,long long > > ranges;
vector< pair< pair<long long,long long>,long long > > act;
set< pair<long long,long long> > s;

vector< pair< pair<long long,long long>,long long> > pts; // num, h, open/close
vector<long long> area;

int main(){
    freopen("input05.txt","r",stdin);
    freopen("output05.txt","w",stdout);

    long long i,j,k;
    long long n;
    long long x,y,z;
    long long q;
    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        ranges.push_back(mp(mp(x,y),z));
        pts.push_back(mp(mp(x,i),0));
        pts.push_back(mp(mp(y,i),1));
    }

    sort(pts.begin(),pts.end());

    long long st = LLONG_MAX;
    long long st_h = 0;
    for(i=0;i<2*n;i++){
        long long idx = pts[i].ft.sd;
        long long h = ranges[idx].sd;
        if(pts[i].sd == 0){
            if(s.empty()){
                s.insert(mp(h,idx));
                st_h = h;
                st = pts[i].ft.ft;
                continue;
            }
            s.insert(mp(h,idx));
        } else if(pts[i].sd == 1){
            s.erase(mp(h,idx));
        }

        if(s.empty()){
            act.push_back(mp(mp(st,pts[i].ft.ft),st_h));
        } else {
            //cout<<"1"<<endl;
            set< pair<long long,long long> >::reverse_iterator rit = s.rbegin();
            if(st_h != rit->first){
                act.push_back(mp(mp(st,pts[i].ft.ft),st_h));
                st_h = rit->first;
                st = pts[i].ft.ft;
            }
            //cout<<"2"<<endl;
        }
    }

   /* cout<<endl;
    for(i=0;i<act.size();i++)
        cout<<act[i].ft.ft<<" "<<act[i].ft.sd<<" "<<act[i].sd<<endl;
    cout<<endl;*/

    for(i=0;i<act.size();i++){
        area.push_back((act[i].ft.sd - act[i].ft.ft)
                       *act[i].sd);
        if(i!=0)
            area[i] = area[i] + area[i-1];
    }

    /*for(i=0;i<area.size();i++)
        cout<<area[i]<<" ";
    cout<<endl;*/

    scanf("%lld",&q);
    for(i=0;i<q;i++){
        scanf("%lld%lld",&x,&y);

        long long stidx = upper_bound(act.begin(),act.end(),mp(mp(x,LLONG_MAX),LLONG_MAX)) - act.begin();
        long long edidx = upper_bound(act.begin(),act.end(),mp(mp(y,LLONG_MAX),LLONG_MAX)) - act.begin();
       // cout<<stidx<<" "<<edidx<<endl;
        stidx--;
        edidx--;

        if(stidx+1<act.size() && act[stidx].ft.sd <= x)
        {
            x = act[stidx+1].ft.ft;
            stidx++;
        }

        if(act[edidx].ft.sd <= y)
        {
            y = act[edidx].ft.sd;
        }

        if(x>=y){
            printf("0\n");
            continue;
        }

        if(stidx<0 && edidx<0){
            printf("0\n");
        } else {
            long long one=0,two=0,three=0;
            if(stidx>=0 && act[stidx].ft.sd - x >=0)
                one = (act[stidx].ft.sd - x)*act[stidx].sd;
            if(edidx-1>=0)
                two = area[edidx-1];
            if(stidx>=0)
                two = two - area[stidx];
            if(edidx>=0 && y-act[edidx].ft.ft >=0)
                three = (y-act[edidx].ft.ft)*act[edidx].sd;
            printf("%lld\n",one+two+three);
        }
    }
    return 0;
}
