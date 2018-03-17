#include<bits/stdc++.h>
using namespace std;

int n;

char sym[110];
char op[110];

map< pair<int,int>,pair<int,int> > memo;

pair<int,int> cal(int l,int h)
{
    int i,j,k;
    int t=0,f=0;
    int lt,lf,rt,rf;

    if(memo.find(make_pair(l,h))!=memo.end())
    {
        return memo[make_pair(l,h)];
    }

    pair<int,int> p;

    if(l==h)
    {
        if(sym[l]=='T')
        {
            return make_pair(1,0);
        }
        else
        {
            return make_pair(0,1);
        }
    }

    for(i=l;i<h;i++)
    {
        p=cal(l,i);
        lt=p.first;
        lf=p.second;

        p=cal(i+1,h);
        rt=p.first;
        rf=p.second;

        if(op[i]=='|')
        {
            t+=lt*rf+lt*rt+lf*rt;
            f+=lf*rf;
        }
        else if(op[i]=='&')
        {
            t+=lt*rt;
            f+=lt*rf+lf*rf+lf*rt;
        }
        else if(op[i]=='^')
        {
            t+=lt*rf+lf*rt;
            f+=lt*rt+lf*rf;
        }
    }

    return memo[make_pair(l,h)]=make_pair(t,f);
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    scanf("%s",sym);
    scanf("%s",op);
    pair<int,int> p=cal(0,n-1);
    printf("%d\n",p.first);
}












