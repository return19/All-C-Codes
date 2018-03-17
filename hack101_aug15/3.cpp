#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[501000],q[501000];
map<int,int> memo;
int n;

int arr[1010000];
int bit[1010000];

void update(int idx,int val)
{
    while(idx<=300100)
    {
        bit[idx]+=val;

        idx+= idx&(-idx);
    }
}

int qry(int idx)
{
    int sum=0;

    while(idx>0)
    {
        sum+=bit[idx];

        idx-= idx&(-idx);
    }

    return sum;
}

int main()
{
    int m,l;
    int i,j,k;
    int x,y;
    int d=0;

    scanf("%d%d%d",&n,&m,&l);

    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].first,&p[i].second);
        arr[++d]=p[i].second;
    }

    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].first,&q[i].second);
        arr[++d]=q[i].second;
        arr[++d]=q[i].second-l-1;
    }

    sort(arr+1,arr+d+1);
    k=0;
    for(i=1;i<=d;i++)
    {
        if(memo[arr[i]]==0)
        {
            memo[arr[i]]=++k;
        }

        //cout<<arr[i]<<" "<<memo[arr[i]]<<endl;
    }

    x=1;
    y=1;

    int ans=0;

    sort(p+1,p+n+1);
    sort(q+1,q+m+1);

    for(i=1;i<=m;i++)
    {
        while(x<=n&&p[x].first<=q[i].first)
        {
            update(memo[p[x].second],1);
            x++;
        }

        while(y<=n&&p[y].first<q[i].first-l)
        {
            update(memo[p[y].second],-1);
            y++;
        }

        ans=max(ans,qry(memo[q[i].second])-qry(memo[q[i].second-l-1]));
    }

    printf("%d\n",ans);

    return 0;
}










