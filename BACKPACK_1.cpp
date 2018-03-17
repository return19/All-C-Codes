#include<bits/stdc++.h>
using namespace std;

typedef struct a
{
	long long vol;
	long long imp;
	long long u;
	long long i;

}elem;

elem arr[110];

long long n;
long long vmax;

long long cmp(elem a,elem b)
{
	return a.u<b.u;
}

long long ismasked(long long mask,long long pos)
{
	if(pos==0)
	{
		if(mask & 1)
			return 1;
		return 0;
}
else
{
	if(mask & (1<<pos))
		return 1;
	return 0;
}
}

void maskit(long long &mask,long long pos)
{
	if(pos==0)
	{
		mask=mask|1;
}
else
{
	mask=mask|(1<<pos);
}
}

map< pair< pair<long long,long long>,long long >,long long> memo;

long long solve(long long idx,long long cur_vol,long long mask)
{
	if(idx==n)
	{
		return 0;
}

long long tk=0,nt=0;
long long temp;

if(memo.find ( make_pair ( make_pair(idx,cur_vol) , mask ) ) !=memo.end() )
	return memo[make_pair(make_pair(idx,cur_vol),mask)];

if(arr[idx].u==0)
{
	nt=solve(idx+1,cur_vol,mask);

	if(arr[idx].vol<=cur_vol){
		temp=mask;
		maskit(temp,arr[idx].i);
		tk = arr[idx].imp*arr[idx].vol + solve(idx+1 , cur_vol - arr[idx].vol ,temp);
}

return memo[make_pair(make_pair(idx,cur_vol),mask)]=max(tk,nt);
}
else
{
	nt=solve(idx+1,cur_vol,mask);

	if(ismasked(mask,arr[idx].u) && cur_vol>=arr[idx].vol)
	{
		tk=arr[idx].imp*arr[idx].vol + solve(idx+1 , cur_vol - arr[idx].vol , mask);
}

return memo[make_pair(make_pair(idx,cur_vol),mask)]=max(tk,nt);
}
}

int main()
{
	long long i,j,k;

	long long test,t;

	scanf("%lld",&test);

for(t=0;t<test;t++)
{
	memo.clear();

	scanf("%lld%lld",&vmax,&n);
	vmax/=10;

	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&arr[i].vol,&arr[i].imp,&arr[i].u);
		arr[i].i=i+1;
		arr[i].vol /= 10;
}

sort(arr,arr+n,cmp);

long long mask=0;

long long ans=solve(0,vmax,0);

printf("%lld\n",ans*10);
}


	return 0;
}
