#include<bits/stdc++.h>
using namespace std;

int n;
int v;

struct elem
{
    int vol;
    int imp;
    int p;
    int idx;
};

elem item[110];

bool cmp(elem a,elem b)
{
    return a.p<b.p;
}

void setVal(int &mask,int x)
{
    mask |= (1<<x);
}

int isSet(int &mask,int x)
{
    int ans=(1<<x)&mask;
	if(ans>0)
	 	return 1;
	 return 0;

}

map< <pair<int,int>,int > memo;

int solve(int cur_item,int cur_vol,int mask)
{

    if(cur_item>n)
        return 0;

    int tk=0,ntk=0;

    if(memo.find(make_pair(make_pair(cur_item,cur_vol),mask))!=memo.end())
        return memo[make_pair(make_pair(cur_item,cur_vol),mask)];

    if(item[cur_item].p==0)
    {
        ntk=solve(cur_item + 1,cur_vol,mask);

        setVal(mask,item[cur_item].idx);

        if(cur_vol + item[cur_item].vol<=v)
            tk=item[cur_item].vol*item[cur_item].imp + solve(cur_item + 1,cur_vol + item[cur_item].vol,mask);

        //mask[item[cur_item].idx]=0;

        return memo[make_pair(make_pair(cur_item,cur_vol),mask)]=max(tk,ntk);
    }
    else
    {
        ntk=solve(cur_item + 1,cur_vol,mask);

        if(isSet(mask,item[cur_item].p))
        {
            setVal(mask,item[cur_item].idx);

            if(cur_vol + item[cur_item].vol<=v)
                tk=item[cur_item].vol*item[cur_item].imp + solve(cur_item + 1,cur_vol + item[cur_item].vol,mask);

            //mask[item[cur_item].idx]=0;
        }

        return memo[make_pair(make_pair(cur_item,cur_vol),mask)]=max(tk,ntk);
    }
}

int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();

        scanf("%d%d",&v,&n);

        v /= 10;

        for(j=1;j<=n;j++)
        {
            scanf("%d%d%d",&item[j].vol,&item[j].imp,&item[j].p);
            item[j].idx=j;

            item[j].vol /= 10;
        }

        sort(item +1,item + n + 1 , cmp);

        //int mask[110];

        //memset(mask,0,sizeof(mask));

        int mask=0;

        int ans=solve(0,0,mask);

        printf("%d\n",ans*10);

    }

    return 0;
}
