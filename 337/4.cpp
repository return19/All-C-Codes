#include<bits/stdc++.h>
using namespace std;

class st
{
    long long s[4001000];
    long long lazy[4001000];
    long long f[4010000];
    long long n;

    void shift(long long idx,long long l,long long r)
    {
        long long mid=l + (r-l)/2;

        if(f[idx]==1){
            update((idx<<1)+1,l,mid,lazy[idx]);
            update((idx<<1)+2,mid+1,r,lazy[idx]);
        }
        lazy[idx]=0;
        f[idx]=0;
    }

    void update(long long idx,long long l,long long r,long long val)
    {
        lazy[idx]+=val;
        s[idx]+=(r-l+1)*val;
        f[idx]=1;
    }

    void build(long long idx,long long l,long long r,long long arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            return;
        }

        long long mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    void increase(long long idx,long long l,long long r,long long ql,long long qr,long long val)
    {
        if(ql>r || qr<l)
            return;

        if(ql<=l&&r<=qr)
        {
            update(idx,l,r,val);
            return;
        }

        shift(idx,l,r);

        long long mid=l + (r-l)/2;

        increase((idx<<1)+1,l,mid,ql,qr,val);
        increase((idx<<1)+2,mid+1,r,ql,qr,val);

        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    long long query(long long idx,long long l,long long r,long long ql,long long qr)
    {
        if(ql>r || qr<l)
            return 0;

        if(ql<=l&&r<=qr)
        {
            return s[idx];
        }

        shift(idx,l,r);

        long long mid=l + (r-l)/2;

        return query((idx<<1)+1,l,mid,ql,qr) + query((idx<<1)+2,mid+1,r,ql,qr);
    }

public:

    st()
    {}

    st(long long n)
    {
        long long i;
        (*this).n=n;

        for(i=0;i<=n*4;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void setN(long long n)
    {
        (*this).n=n;

        for(long long i=0;i<=4*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void build(long long arr[])
    {
        build(0,0,n-1,arr);
    }

    void increase(long long l,long long r,long long val)
    {
        increase(0,0,n-1,l,r,val);
    }

    long long query(long long l,long long r)
    {
        return query(0,0,n-1,l,r);
    }


};

long long t11[4010000];
    long long cnt=1;
void inc(long long i, long long delta)
{
	for (; i <= cnt +10; i = (i|(i + 1)))
		t11[i] += delta;
}

long long sum(long long r)
{
	long long res = 0;
	for (; r >= 0; r = (r&(r + 1)) - 1)
		res += t11[r];
	return res;
}

long long sum(long long l, long long r)
{
	return sum(r) - sum(l - 1);
}

st one(1);
map<long long,long long> memo;
map<long long,long long>::iterator it;
long long n;



vector< pair< long long,pair<long long,long long> > > event;

struct inter
{
    long long x1;
    long long x2;
    long long y1;
    long long y2;
};
vector<inter> ax1;
vector<inter> ay1;
vector<inter> ax;
vector<inter> ay;

long long cmp1(inter a,inter b) // ax
{
    if(a.y1==b.y1)
    {
        if(a.x1==b.x1)
            return a.x2<b.x2;
        return a.x1<b.x1;
    }
    return a.y1<b.y1;
}

long long cmp2(inter a,inter b)  //bx
{
    if(a.x1==b.x1)
    {
        if(a.y1==b.y1)
        {
            return a.y2<b.y2;
        }
        return a.y1<b.y1;
    }
    return a.x1<b.x1;
}

int main()
{
    long long i,j,k;
    long long x1,y1,x2,y2;

    inter t;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);

        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if(y1>y2){
            swap(y1,y2);
            swap(x1,x2);
        }

        memo[x1];
        memo[x2];
        memo[y1];
        memo[y2];
        t.x1=x1;
        t.x2=x2;
        t.y1=y1;
        t.y2=y2;
        if(y1==y2)
            ax.push_back(t);
        else
            ay.push_back(t);
    }
    cnt=1;
    for(it=memo.begin();it!=memo.end();it++)
    {
        memo[it->first]=cnt++;
    }

    sort(ax.begin(),ax.end(),cmp1);
    sort(ay.begin(),ay.end(),cmp2);

    one.setN(cnt+10);

    long long ans=0;

    if(ax.size()>0){
        x1=ax[0].x1;
        x2=ax[0].x2;
        y1=ax[0].y1;

        for(i=1;i<ax.size();i++)
        {
            if(ax[i].y1!=y1 || ax[i].x1>x2)
            {
                t.x1=x1;
                t.x2=x2;
                t.y1=t.y2=y1;
                ax1.push_back(t);
                x1=ax[i].x1;
                x2=ax[i].x2;
                y1=ax[i].y1;
            }
            else
                x2=max(x2,ax[i].x2);
        }
        t.x1=x1;
        t.x2=x2;
        t.y1=t.y2=y1;
        ax1.push_back(t);
    }

    if(ay.size()>0){
        x1=ay[0].x1;
        y1=ay[0].y1;
        y2=ay[0].y2;

        for(i=1;i<ay.size();i++)
        {
            if(ay[i].x1!=x1 || ay[i].y1>y2)
            {
                t.x1=t.x2=x1;
                t.y1=y1;
                t.y2=y2;
                ay1.push_back(t);
                x1=ay[i].x1;
                y1=ay[i].y1;
                y2=ay[i].y2;
            }
            else
                y2=max(y2,ay[i].y2);
        }
        t.x1=t.x2=x1;
        t.y1=y1;
        t.y2=y2;
        ay1.push_back(t);
    }

    for(i=0;i<ax1.size();i++)
    {
        ans+= (ax1[i].x2 - ax1[i].x1 + 1);
    }

    for(i=0;i<ay1.size();i++)
    {
        ans+= (ay1[i].y2 - ay1[i].y1 + 1);
    }

    //cout<<ans<<endl;

    for(i=0;i<ax1.size();i++)
    {
        event.push_back(make_pair(memo[ax1[i].x1],make_pair(-1,memo[ax1[i].y1])));
        event.push_back(make_pair(memo[ax1[i].x2],make_pair(1,memo[ax1[i].y1])));
    }

    for(i=0;i<ay1.size();i++)
    {
        event.push_back(make_pair(memo[ay1[i].x1],make_pair(0,i)));
    }

    sort(event.begin(),event.end());

    for(i=0;i<event.size();i++)
    {
        long long t=event[i].second.first;

        if(t==-1)
        {
            inc(event[i].second.second,1);
        }
        else if(t==1)
        {
            inc(event[i].second.second,-1);
        }
        else{
            long long j=event[i].second.second;
            ans -= sum(memo[ay1[j].y1],memo[ay1[j].y2]);
            //cout<<"here "<<one.query(ay1[j].y1,ay1[j].y2)<<endl;
        }
    }

    printf("%lld\n",ans);



    return 0;
}










