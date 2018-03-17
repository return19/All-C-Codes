#include<bits/stdc++.h>
using namespace std;

vector< pair<long long,long long> > yy;
vector< pair<long long,long long> > kb;
long long n;
long long x1,x2;

int main()
{
    long long i,j,k;
    long long x,y;

    scanf("%lld",&n);
    scanf("%lld%lld",&x1,&x2);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        kb.push_back(make_pair(x,y));
        long long miny=x1*x + y;
        long long maxy=x2*x + y;

        yy.push_back(make_pair(miny,maxy));
    }

    sort(yy.begin(),yy.end());

   // for(i=0;i<yy.size();i++)
     //   cout<<yy[i].first<<" "<<yy[i].second<<endl;
    long long cur=LLONG_MIN;
    for(i=0;i<yy.size();i++)
    {
        if(yy[i].second<cur)
        {
            printf("YES\n");
            return 0;
        }
        cur=max(cur,yy[i].second);
    }

    printf("NO\n");
    return 0;
}
















