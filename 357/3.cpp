#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> > s;
string str;

vector< pair<string,int> > v;

int main()
{
    int i,j,k;
    int n;
    int c=1,x,y,z;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        cin>>str;
        if(str=="removeMin")
        {
            if(s.empty()){
                v.push_back(make_pair("insert",1));
                v.push_back(make_pair(str,0));
            }else{
                v.push_back(make_pair(str,0));
                s.erase(*(s.begin()));
            }
        }else if(str=="insert"){
            cin>>x;
            v.push_back(make_pair(str,x));
            s.insert(make_pair(x,c++));

        }else if(str=="getMin"){
            cin>>x;
            while(!s.empty() && s.begin()->first < x){
                v.push_back(make_pair("removeMin",0));
                s.erase(*(s.begin()));
            }

            if(!s.empty() && s.begin()->first == x){
                v.push_back(make_pair(str,x));
            }else{
                s.insert(make_pair(x,c++));
                v.push_back(make_pair("insert",x));
                v.push_back(make_pair(str,x));
            }
        }
    }

    cout<<v.size()<<endl;
    for(i=0;i<v.size();i++){
        if(v[i].first=="removeMin"){
            cout<<v[i].first<<endl;
        }else{
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    return 0;
}

