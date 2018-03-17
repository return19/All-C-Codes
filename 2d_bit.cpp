#include<bits/stdc++.h>
using namespace std;

class bit
{

    int arr[111][111];
    int n;

public:

    bit(){}

    bit(int n)
    {
        int i,j;
        for(i=0;i<=n+10;i++)
            for(j=0;j<=n+10;j++)
                arr[i][j]=0;

        (*this).n=n;
    }

    void setn(int n)
    {
        (*this).n=n;
    }

    void init()
    {
        int i,j;

        for(i=0;i<=n+10;i++)
            for(j=0;j<=n+10;j++)
                arr[i][j]=0;
    }

    void increase(int x,int y,int val)
    {
        if(x==0||y==0)
            return;

        int i,j;

        for(i=x;i<=n;i += (i)&(-i))
        {
            for(j=y;j<=n;j += (j)&(-j))
                arr[i][j] += val;
        }
    }


    int query(int x,int y)
    {


        int sum=0;

        int i,j;

        for(i=x;i>0;i -= (i)&(-i))
        {
            for(j=y;j>0;j -= (j)&(-j))
                sum += arr[i][j];
        }

        return sum;
    }

    int query(int a,int b,int x,int y)
    {
        return query(x,y)-query(a-1,y)-query(x,b-1)+query(a-1,b-1);
    }
};

int main()
{
    int i,j,k;
    int n;
    int t;

    cin>>n;

    bit bt(n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&t);

            bt.increase(i,j,t);
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<bt.query(i,j)<<" ";
        cout<<endl;
    }

    cout<<bt.query(2,2,3,3)<<endl;

    return 0;
}
