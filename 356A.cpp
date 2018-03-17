#include<bits/stdc++.h>
using namespace std;

int n,m;

int ans[501000];

class st
{
    int s[4001000];
    int n;

    void increase(int idx,int l,int r,int ql,int qr,int val)
    {
        //cout<<"here "<<idx<<endl;

        if(ql>r || qr<l)
            return;

        if(s[idx]==-1)
            return;

        if(l==r)
        {
            ans[l]=val;

            if(l!=val)
                s[idx]=-1;
            return;
        }

        int mid=l + (r-l)/2;

        increase((idx<<1)+1,l,mid,ql,qr,val);
        increase((idx<<1)+2,mid+1,r,ql,qr,val);

        if(s[(idx<<1)+1]==-1 && s[(idx<<1)+2]==-1)
            s[idx]=-1;
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

    void increase(int l,int r,int val)
    {
        increase(0,0,n-1,l,r,val);
    }
};

// see limits

st one(1);

int main()
{
    int i,j,k;
    int x,y,z;

    scanf("%d%d",&n,&m);

    one.setN(n+10);

    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        x--;    y--;    z--;

        one.increase(x,y,z);
    }

    for(i=0;i<n;i++)
    {
        if(ans[i]==i)
            printf("0 ");
        else
            printf("%d ",ans[i]+1);
    }


    return 0;
}












