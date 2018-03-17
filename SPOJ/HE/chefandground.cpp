#include<iostream>
using namespace std;

int largestNumArr(int a[],int index)
{
    int g,i;
    g=0;
    for(i=0;i<index;i++)
    {
        if(a[g]<a[i])
            g=i;
    }
    return g;
}
int main()
{
    int a[10005],b[105],n,m,i,t;
    long long int g,j,blockMinCount=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        for(j=0;j<n;j++)
            cin>>a[j];
        g=largestNumArr(a,n);

        blockMinCount=0;
        for(j=0;j<n;j++)
            blockMinCount+=g-a[j];

        m=m-blockMinCount;
        if(m<0)
        {
            b[i]=0;
            continue;
        }

        if(blockMinCount==0&&(m==0||m%n==0))
        {
            b[i]=1;
        }
        else if(m<blockMinCount||m%n!=0)
        {
            b[i]=0;
        }
        else
        {
            b[i]=1;
        }

    }

    for(i=0;i<t;i++)
    {
        if(b[i]==1)
            {cout<<"Yes"<<endl;
            }
        else
        {
            cout<<"No"<<endl;
        }

    }

    return 0;
}
