#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[101000];
vector< vector<int> > occ(101000);

int s[101000];

int temp[101000];

vector<int> p;

class st
{
    int s[401000];
    int n;

    void build(int idx,int l,int r,int arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            return;
        }

        int mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=max(s[(idx<<1)+1],s[(idx<<1)+2]);
    }

    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>r || qr<l)
            return INT_MIN;

        if(ql<=l&&r<=qr)
        {
            return s[idx];
        }

        int mid=l + (r-l)/2;

        return max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
    }

public:

    st()
    {}

    st(int n)
    {
        int i;
        (*this).n=n;

        for(i=0;i<=n*4;i++)
        {
            s[i]=0;

        }
    }

    void setN(int n)
    {
        (*this).n=n;

        for(int i=0;i<=4*n;i++)
        {
            s[i]=0;

        }
    }

    void build(int arr[])
    {
        build(0,0,n-1,arr);
    }

    int query(int l,int r)
    {
        return query(0,0,n-1,l,r);
    }


};

void sieve()
{
    int i,j,k;

    s[0]=s[1]=1;

    for(i=2;i<320;i++)
    {
        if(s[i]==0)
        {
            p.push_back(i);
            k=2;
            for(j=i*k;j<320;j=i*k)
            {
                s[j]=1;

                k++;
            }
        }
    }

   // cout<<p[p.size()-1]<<endl;
}

st one[410];

st tst;

int main()
{
    int test,i,j,k;

    sieve();

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        occ[arr[i]].push_back(i);
    }

    for(i=0;i<p.size();i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[j]%p[i]==0)
            {
                temp[j]=arr[j];
            }
            else
                temp[j]=-1;
        }

        one[p[i]].setN(n+5);
        one[p[i]].build(temp);
    }

    int g,l,r;
    int ans=-1;

    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&g,&l,&r);
        l--;
        r--;

        ans=-1;

        for(j=0;j<p.size();j++)
        {
            if(g%p[j]==0)
                ans=max(ans,one[p[j]].query(l,r));

            while(g%p[j]==0)
                g/=p[j];
        }

        if(g>1){
            for(j=1;g*j<100010;j++)
            {
                if(upper_bound(occ[g*j].begin(),occ[g*j].end(),r)-lower_bound(occ[g*j].begin(),occ[g*j].end(),l)>=1)
                    ans=max(ans,g*j);
            }
        }

        if(ans==-1)
        {
            printf("-1 -1\n");
        }
        else
        {
            int ans2=upper_bound(occ[ans].begin(),occ[ans].end(),r)-lower_bound(occ[ans].begin(),occ[ans].end(),l);

            printf("%d %d\n",ans,ans2);
        }
    }

    return 0;
}







