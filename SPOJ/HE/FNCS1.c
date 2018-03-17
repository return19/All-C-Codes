#include<iostream>
using namespace std;

int a[1000010];
int fn[1000010];
int fnp[1000010][2];
int main()
{
    int n,l,i,j,k,r,sum=0,sum1=0,test,t,x,y;
    cin>>n;

    for(i=0;i<n;i++);
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
        sum=0;
        cin>>l;
        cin>>r;
       fnp[i][0]=l;
       fnp[i][1]=r;
       for(j=l;j<=r;j++)
       {
        sum=sum+a[j];
       }
       fn[i]=sum;
    }

    cin>>test;
    for(j=0;j<test;j++)
    {
     cin>>t;
     cin>>x;
     cin>>y;
    if(t==1)
    {
        for(i=0;i<n;i++)
        {
            if(fnp[i][0]>=x&&fnp[i][1]<=x)
            {
                fn[i]=fn[i]+(y-x);
            }
        }
    }
    else
    {
        sum=0;
        for(i=x;i<=y;i++)
        {
            sum=sum+fn[i];
        }
        cout<<sum<<endl;
    }
    }

    return 0;
}

