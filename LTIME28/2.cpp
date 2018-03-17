#include<bits/stdc++.h>
using namespace std;
//many lists

/*int p[101000];

int fnd(int x)
{
    if(x==p[x])
        return x;

    return p[x]=fnd(p[x]);
}

void unn(int x,int y)
{
    int i,j;
    i=fnd(x);
    j=fnd(y);

    if(i!=j)
    {
        p[y]=i;
    }
}

void init_dsu(int n)
{
    int i=0;

    for(i=0;i<=n;i++)
        p[i]=i;
}*/

set<int> s[101000];

int main()
{
    int i,j,k;
    int t,test;
    int n,m;

    int x,y,l,r;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d",&t);

        if(t==0)
        {
            scanf("%d%d%d",&l,&r,&x);

            for(j=l;j<=r;j++)
                s[j].insert(x);
        }
        else
        {
            scanf("%d",&x);

            printf("%d\n",s[x].size());
        }
    }

    return 0;
}









