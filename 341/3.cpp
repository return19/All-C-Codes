#include<bits/stdc++.h>
using namespace std;

long long n,p;

long long numDiv(long long x,long long y)
{
    if(x<=1)
        return y/p;

    return (y/p - (x-1)/p);
}

double prob[101000];

int main()
{
    long long i,j,k;
    long long x,y;

    scanf("%lld%lld",&n,&p);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        prob[i]=(double)numDiv(x,y)/(y-x+1);
    }

   /* for(i=0;i<n;i++)
        cout<<prob[i]<<" ";
    cout<<endl;*/
    double ans=0;
    double fr,sc;
    for(i=0;i<n;i++)
    {
        fr=prob[i];
        sc=prob[(i+1)%n];
        //cout<<x<<" "<<y<<endl;
        ans += (fr + sc - fr*sc)*2000;
    }

    printf("%.8lf\n",ans);
    return 0;
}
