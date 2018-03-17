#include<bits/stdc++.h>
using namespace std;

set< pair<long long,long long> > s;
set< pair<long long,long long> >::iterator it,it1,it2;
set< pair<long long,long long> >::reverse_iterator rit;
vector<long long> ans;

map<long long,long long> memo;

int main(){
    long long i,j,k;
    long long n;
    long long x,y,z;

    scanf("%lld",&n);

    scanf("%lld",&x);
    s.insert(make_pair(x,0));

    k=1;

    memo[x]=k++;

    for(i=1;i<n;i++){
        scanf("%lld",&x);

        it1=s.lower_bound(make_pair(x,(long long)0));
        it2=it1;
        it2--;

        //cout<<it2->first<<" "<<it1->first<<endl;
       /* for(it=s.begin();it!=s.end();it++)
            cout<<it->first<<" ";
        cout<<endl;*/

        if(it1==s.end()){
          //  cout<<"here"<<endl;
          //  cout<<it1->first<<" "<<rit->first<<endl;

            ans.push_back((*it2).first);
            pair<long long,long long> p= (*it2);

            s.insert(make_pair(x,0));
            s.erase(p);

            if(p.second==0)
                s.insert(make_pair(p.first,2));
            else
                s.insert(make_pair(p.first,3));

        }else if(it1==s.begin()){
          //  cout<<"2"<<endl;
            ans.push_back((*it1).first);
           // cout<<"in"<<endl;
            pair<long long,long long> p= (*it1);

            s.insert(make_pair(x,0));
            s.erase(p);

           if(p.second==0)
                s.insert(make_pair(p.first,1));
            else
                s.insert(make_pair(p.first,3));
        }else{
            pair<long long,long long> p1,p2;
          //  cout<<"3"<<endl;

            p1=(*it2);
            p2=(*it1);
           // cout<<p1.first<<" "<<p2.first<<endl;
            long long f=0;
            if((p1.second==1|| p1.second==0) && (p2.second==2||p2.second==0)){
                if(memo[p1.first]<memo[p2.first])
                    f=1;
                else
                    f=2;
            }else if(p1.second==1|| p1.second==0)
                f=1;
            else
                f=2;

          //  cout<<":"<<f<<endl;

            s.insert(make_pair(x,0));

            if(f==1){
                ans.push_back(p1.first);
                s.erase(p1);

                if(p1.second==0)
                    s.insert(make_pair(p1.first,2));
                else
                    s.insert(make_pair(p1.first,3));
            }else{//f==2
                ans.push_back(p2.first);
                s.erase(p2);
                if(p2.second==0)
                    s.insert(make_pair(p2.first,1));
                else
                    s.insert(make_pair(p2.first,3));
            }
        }
        memo[x]=k++;
    }


    for(i=0;i<n-1;i++)
        printf("%lld ",ans[i]);

    return 0;
}

