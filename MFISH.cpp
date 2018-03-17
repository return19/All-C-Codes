#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[101000];

struct elem
{
    int ship;
    int l;
};

elem a[101000];

int csum[101000];

map< pair<int,int>,int > memo;

int solve(int x,int pos)
{
    if(x>m)
        return 0;

    if(pos>n)
        return INT_MIN;

    int i,j,k;

    int idx=a[x].ship;
    int len=a[x].l;

    if(pos>idx)
        return INT_MIN;

    int st=max(pos,idx-len+1);

    if(memo.find(make_pair(x,st))!=memo.end())
        return memo[make_pair(x,st)];

    int ans=INT_MIN;
    int temp;
    int f=0;

    for(i=st;i<=n&&i<=idx;i++)
    {
        temp=solve(x+1,i+len);

        if(temp!=INT_MIN)
            f=1;

        ans=max(ans,csum[i+len-1]-csum[i-1]+temp);
    }

    if(f==0)
        return memo[make_pair(x,st)]=INT_MIN;

    return memo[make_pair(x,st)]=ans;

}


//map< pair<pair<int,int>,int>,int > memo;

/*int solve(int x,int t[])
{
    if(x>m)
        return 0;

    int i,j,k;

    int len=l[x];
    int idx=ship[x];
    int st=idx;
    int ed=idx;

    if(t[idx]==1)
        return INT_MIN;



    for(i=idx-1;i>=1&&i>=idx-len+1;i--)
    {
        if(t[i]==1)
            break;
        st=i;
    }

    for(i=idx+1;i<=n&&i<=idx+len-1;i++)
    {
        if(t[i]==1)
            break;
        ed=i;
    }

    if(ed-st+1<len)
        return INT_MIN;

    if(memo.find(make_pair(make_pair(x,st),ed))!=memo.end())
        return memo[make_pair(make_pair(x,st),ed)];

    int ans=INT_MIN;

    int sum=0;

    for(i=st;i<=n&&i<st+len;i++)
     {
         t[i]=1;
         sum += arr[i];
     }

    int temp;

    int f=0;

  /*  for(i=1;i<=n;i++)
        cout<<t[i]<<" ";
    cout<<endl;
*/
   /* for(i=st;i<=n&&i+len-1<=ed;i++)
    {
        temp=solve(x+1,t);

        if(temp!=INT_MIN)
            f=1;

        ans=max(ans,sum + temp);

        if(i+len-1!=ed){
            t[i]=0;
            t[i+len]=1;
            sum -= arr[i];
            sum += arr[i+len];
        }
    }

    //cout<<x<<" "<<ans<<endl;

    for(i=st;i<=n&&i<=ed;i++)
        t[i]=0;

    if(f==0)
        return memo[make_pair(make_pair(x,st),ed)]=INT_MIN;

    return memo[make_pair(make_pair(x,st),ed)]=ans;
}
*/
 //int t[101000];

int cmp(elem x,elem y)
{
    return x.ship<y.ship;
}

int main()
{
    int i,j,k;

    csum[0]=0;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);

        csum[i]= arr[i]+csum[i-1];
    }

    scanf("%d",&m);

    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].ship,&a[i].l);
    }

    sort(a+1,a+m+1,cmp);

    int ans=solve(1,1);

    printf("%d\n",ans);

    return 0;
}








