#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > v;

int main()
{
    int i,j,k;
    int n,s;
    int time=0;
    int x,y;

    scanf("%d%d",&n,&s);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end());

    int cur=s;

    for(i=v.size()-1;i>=0;i--)
    {
        x=v[i].first;
        y=v[i].second;

        time=max(y,time + (cur-x));
        cur=x;
    }

    time+=(cur);

    printf("%d\n",time);

    return 0;
}
