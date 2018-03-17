#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int i;

    for(i=0;i<6;i++)
    {
        int t;
        scanf("%d",&t);
        v.push_back(t);
    }

    int x;
    cin>>x;

    cout<<lower_bound(v.begin(),v.end(),x)-v.begin()<<" "<<upper_bound(v.begin(),v.end(),x)-v.begin()<<endl;

 cin>>x;

    cout<<lower_bound(v.begin(),v.end(),x)-v.begin()<<" "<<upper_bound(v.begin(),v.end(),x)-v.begin()<<endl;

 cin>>x;

    cout<<lower_bound(v.begin(),v.end(),x)-v.begin()<<" "<<upper_bound(v.begin(),v.end(),x)-v.begin()<<endl;


    return 0;
}
