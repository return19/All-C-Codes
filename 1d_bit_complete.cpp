#include<bits/stdc++.h>
using namespace std;

//Range update range query

class bit
{
public:
    int a[10100];
    int b[10100];
    int n;

public:

    bit(){}

    bit(int n)
    {
        int i;
        for(i=0;i<=n+10;i++)
            a[i]=0;

        for(i=0;i<=n+10;i++)
            b[i]=0;

        (*this).n=n;
    }

    void setn(int n)
    {
        (*this).n=n;
    }

    void init()
    {
        int i;
        for(i=0;i<=n+10;i++)
            a[i]=0;

            for(i=0;i<=n+10;i++)
            b[i]=0;
    }

    void increase(int x,int y,int val)
    {
        int i;

        //cout<<"inc 1 "<<endl;

        increase(a,x,val);
        increase(a,y+1,-1*val);

        increase(b,x,-1*val*(x-1));
        increase(b,y+1,val*(x-1));
        increase(b,y+1,(y-x+1)*val);
    }

    int query(int x,int y)
    {
        return query(a,y)*y + query(b,y) - (query(a,x-1)*(x-1) + query(b,x-1));
    }

    void increase(int arr[],int idx,int val)
    {
        //cout<<"now"<<endl;
        //cout<<idx<<" "<<val<<endl;

        if(idx<=0)
            return;

        for(int i=idx;i<=n+1;)
        {
            arr[i] += val;

            i += (i)&(-i);

        }
    }

    int query(int arr[],int idx)
    {
        int sum=0;

        while(idx>0)
        {
            sum += arr[idx];

            idx -= (idx)&(-idx);
        }

        return sum;
    }

};

int main()
{
    //cout<<"here"<<endl;

    int i,j,k;
    int n;
    int t;

    cin>>n;

    bit bt(n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);

        bt.increase(i,i,t);
    }

    for(i=1;i<=n;i++)
    {
        cout<<bt.query(i,i)<<" ";
    }

    cout<<endl<<bt.query(4,7)<<endl;

    return 0;
}


