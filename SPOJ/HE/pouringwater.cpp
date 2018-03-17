#include<iostream>
using namespace std;

int main()
{
    int t,i;
    long int a,b,c,d,n[105];
    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(b>a)
        {
            d=b-a;
        }
        else
        {
            d=a-b;
        }

        if((a==b&&a==c)||(a==c||b==c))
        {
            n[i]=1;
        }
        else if((c>a&&c>b)||(c%d!=0&&c%a!=0&&c%b!=0))
        {
            n[i]=-1;
        }
        else if(c==0)
        {
            n[i]=0;
        }
        else if(c%a==0)
        {
            n[i]=2*(c/a);
        }
        else if(c%b==0)
        {
            n[i]=2*(c/b);
        }
        else
        {
            n[i]=4*(c/d)-2;
        }
    }

    for(i=0;i<t;i++)
    {
        cout<<n[i]<<endl;
    }

    return 0;
}
