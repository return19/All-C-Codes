#include<bits/stdc++.h>
using namespace std;



int main()
{
    int i,j,k;
    int n;

    int mn1,mx1;
    int mn2,mx2;
    int mn3,mx3;

    cin>>n;

    cin>>mn1>>mx1;
    cin>>mn2>>mx2;
    cin>>mn3>>mx3;

    i=mn1;
    j=mn2;
    k=mn3;

    n=n-i-j-k;

    mx1=mx1-i;
    mx2=mx2-j;
    mx3=mx3-k;

    if(n<=mx1)
    {
        i=i+n;
        n=0;
    }
    else
    {
        i=i+mx1;
        n=n-mx1;
    }



    if(n<=mx2)
    {
        j=j+n;
        n=0;
    }
    else
    {
        j=j+mx2;
        n=n-mx2;
    }


    if(n<=mx3)
    {
        k=k+n;
        n=0;
    }
    else
    {
        k=k+mx3;
    }

    cout<<i<<" "<<j<<" "<<k<<endl;

    return 0;
}










