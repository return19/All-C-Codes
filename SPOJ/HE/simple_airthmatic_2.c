#include<iostream>
using namespace std;
long long test,i,a,b;
char o;
long long cal()
{
    if(o=='+')
    {
        return (a+b);
    }
    else if(o=='-')
    {
        return (a-b);
    }
    else if(o=='*')
    {
        return (a*b);
    }
    else if(o=='/')
    {
        return (a/b);
    }
    else if(o=='%')
    {
        return (a%b);
    }
}
int main()
{
    cin>>test;

    for(i=0;i<test;i++)
    {
        cin>>a;
        cin>>o;
        while(o!='=')
        {
            cin>>b;
            a=cal();
            cin>>o;
        }
        cout<<a<<endl;
    }
    return 0;
}
