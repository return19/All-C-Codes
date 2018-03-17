#include<bits/stdc++.h>
using namespace std;

int m,n,k;

map<int,int> dc;
map<int,int> city_id;

map<int,int>::iterator it;

vector< vector<int> > v;

int city[110];

int pin[110];

int pr[110];

int q[110];

int c=0;

int l,r;

int mx;

int memo1[25][1100][25];
int memo2[25][1100][25];

pair<int,int> solve(int idx,int sp,int num)
{
    int i,j;

    if(sp>r)
        return make_pair(INT_MIN,0);

    if(num==k)
    {
        if(sp>=l&&sp<=r)
        {
                return make_pair(0,1);
        }
        return make_pair(INT_MIN,0);
    }

    if(idx==m)
    {
        if(num==k&&sp>=l&&sp<=r)
        {
           return make_pair(0,1);
        }
        return make_pair(INT_MIN,0);
    }

    if(memo1[idx][sp][num]!=-1)
        return make_pair(memo1[idx][sp][num],memo2[idx][sp][num]);

    int ans=0;
    int c=0;

    pair<int,int> p;

    p=solve(idx+1,sp,num);

    ans=p.first;
    c=p.second;

    for(i=0;i<v[idx].size();i++)
    {
        p=solve(idx+1,sp + pr[v[idx][i]],num+1);

        if(p.first!=INT_MIN&&ans<p.first + q[v[idx][i]])
        {
            ans=p.first + q[v[idx][i]];
            c=p.second;
        }
        else if(p.first!=INT_MIN&&ans==p.first + q[v[idx][i]])
        {
            c+=p.second;
        }
    }

    memo1[idx][sp][num]=ans;
    memo2[idx][sp][num]=c;

    return make_pair(ans,c);

}

int main()
{
    int i,j;
     int x,y,z;

    scanf("%d%d%d",&m,&n,&k);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        dc[x]=y;
    }

    i=0;

    for(it=dc.begin();it!=dc.end();it++)
    {
        city_id[it->first]=i;

        i++;
    }

    v.resize(n+1);

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        v[city_id[x]].push_back(i);

        pr[i]=y+dc[x];
        q[i]=z;
    }

    scanf("%d%d",&l,&r);

    c=0;
    mx=INT_MIN;

    pair<int,int> p;

    for(x=0;x<25;x++)
        for(y=0;y<1080;y++)
            for(z=0;z<25;z++){
                memo1[x][y][z]=-1;
                memo2[x][y][z]=-1;
            }

    p=solve(0,0,0);

    if(p.first==INT_MIN)
    {
        printf("-1\n");
    }
    else
        printf("%d %d\n",p.first,p.second);

    return 0;
}
