//mdist
#include<bits/stdc++.h>
using namespace std;

long long x[110000];
long long y[110000];

long long abs1(long long x)
{
    if(x>=0)
        return x;
    return x*(-1);
}

int main()
{
    long long test,i,j,k,n,q;
    long long idx,l,r;
    char ch;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
    }

    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        ch=getchar();
        ch=getchar();


        if(ch=='U')
        {
            //cout<<"upd"<<endl;
            scanf("%lld%lld%lld",&idx,&l,&r);

            x[idx]=l;
            y[idx]=r;
        }
        else if(ch=='Q')
        {
            //cout<<"qry"<<endl;
            scanf("%lld%lld",&l,&r);

            long long max1=-999999999;

            for(j=l;j<=r;j++)
            {
                for(k=j+1;k<=r;k++)
                {
                    if(max1<abs1(x[j]-x[k])+abs1(y[j]-y[k]))
                        max1=abs1(x[j]-x[k])+abs1(y[j]-y[k]);
                }
            }

            printf("%lld\n",max1);
        }

    }

    return 0;
}
