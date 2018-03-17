#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<int,int> > v;//ed,st

int main()
{
    int i,j,k;
    int n;
    int x,y;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v.push_back(mp(x+y,x));
    }

    sort(v.begin(),v.end());

    if(n==0)
    {
        printf("0\n");
        return 0;
    }

    int ans=1;
    int cur=v[0].ft;

    for(i=1;i<n;)
    {
        while(i<n && v[i].sd <= cur)
            i++;
        if(i==n)
            break;
        ans++;
        cur=v[i].ft;
        i++;
    }

    printf("%d\n",ans);

    return 0;
}
















