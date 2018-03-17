#include<bits/stdc++.h>
using namespace std;

long long n,k;

long long arr[201000];

struct elem
{
    long long num;
    long long i;
};

elem sorted[201000];

long long operator <(elem a,elem b)
{
    if(a.num==b.num)
        return a.i<b.i;
    return a.num<b.num;
}

long long cmp(elem a,elem b)
{
    if(a.num==b.num)
        return a.i<b.i;
    return a.num<b.num;
}

map< pair<long long,long long>,long long > memo1;

long long bs(long long x,long long idx)
{
    if(memo1.find(make_pair(x,idx))!=memo1.end())
        return memo1[make_pair(x,idx)];

    long long l,r;
/*
    l=lower_bound(sorted,sorted + n,x,cmp1)-sorted;
    r=upper_bound(sorted,sorted + n,x,cmp2)-sorted;
*/
    elem t;
    t.num=x;
    t.i=idx;

    long long ans=lower_bound(sorted,sorted+n,t)-sorted;

    return memo1[make_pair(x,idx)]=ans;
}

long long memo[201000][4];
long long base[201000][4];


long long solve(long long idx,long long l)
{
    if(l==1)
        return 1;
    if(idx==n)
        return 0;

    if(base[idx][l]==1)
        return memo[idx][l];
    base[idx][l]=1;

    long long bs_ans=bs(arr[idx]*k,idx+1);
    long long tk=0,nt;

   // cout<<bs_ans<<" "<<arr[idx]*k<<" "<<idx+1<<endl;

    if(sorted[bs_ans].num != arr[idx]*k)
        tk=0;
    else{
        while(sorted[bs_ans].num==arr[idx]*k){
                tk+=solve(sorted[bs_ans].i,l-1);
                bs_ans++;
        }
    }

    return memo[idx][l]=tk;
}

int main()
{
    long long i,j;
    long long x,y;
    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);

        sorted[i].num=arr[i];
        sorted[i].i=i;
    }

    sort(sorted,sorted+n,cmp);

    /*for(i=0;i<n;i++)
    {
        cout<<sorted[i].num<<" "<<sorted[i].i<<endl;
    }
    cout<<" ---------"<<endl;

    for(i=0;i<100;i++)
    {
        scanf("%lld%lld",&x,&y);

        cout<<bs(x,y)<<endl;
    }*/

    long long ans=0;

    for(i=0;i<n;i++)
        ans += solve(i,3);

    printf("%lld\n",ans);

    return 0;
}
