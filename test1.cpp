#include<bits/stdc++.h>
using namespace std;

set<int> s;

int main()
{
    int i,j,k;

    for(i=0;i<5;i++)
        s.insert(i);

    for(set<int>::iterator it = s.begin();it!=s.end();){
        s.erase(it);
        it++;
        cout<<(*it)<<endl;
    }

    return 0;
}
