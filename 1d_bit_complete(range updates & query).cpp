
#include<bits/stdc++.h>
using namespace std;

class bit
{

    int a[10100];
    int b[10100];
    int n;
    int i,j,k;

public:

    bit(){}

    bit(int n)
    {
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
        for(i=0;i<=n+10;i++)
            a[i]=0;

            for(i=0;i<=n+10;i++)
            b[i]=0;
    }

    void increase(int x,int y,int val)
    {
        int i;

        increase(a,x,val);
        increase(a,y+1,-1*val);

        increase(b,x-1,-1*val*(x-1));
        increase(b,y+1,val*(x-1));
    }

    int query(int x,int y)
    {
        return query(a,x,y) + query(b,x,y);
    }

    void increase(int arr[],int idx,int val)
    {
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

    int query(int arr[],int x,int y)
    {
        return query(arr,y)-query(arr,x-1);
    }
};

int main()
{
    cout<<"here"<<endl;

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

    cout<<endl<<bt.query(4,6)<<endl;

    return 0;
}


