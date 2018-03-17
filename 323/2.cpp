#include<bits/stdc++.h>
using namespace std;
//C

multiset<int> s;
vector<int> ans;
multiset<int>::reverse_iterator rit;

int main()
{
    int i,j,k;
    int n;
    int x,y,z;

    scanf("%d",&n);

    for(i=0;i<n*n;i++)
    {
        scanf("%d",&x);
        s.insert(x);
    }

    for(;!s.empty();)
    {
        rit=s.rbegin();
        int x=(*rit);
       // cout<<x<<endl;

        for(i=0;i<ans.size();i++)
        {
            multiset<int>::iterator it=s.find(__gcd(x,ans[i])),it1;
            it1=it;
            it1++;
            it1++;
            s.erase(it,it1);

        }
        multiset<int>::iterator it=s.find(x),it1;
        it1=it;
        it1++;
        s.erase(it,it1);
        ans.push_back(x);

        /*for(multiset<int>::reverse_iterator it=s.rbegin();it!=s.rend();it++)
            cout<<(*it)<<" ";
        cout<<endl;*/

        //cout<<"h"<<endl;
    }

    for(i=0;i<n;i++)
        printf("%d ",ans[i]);

    return 0;
}

