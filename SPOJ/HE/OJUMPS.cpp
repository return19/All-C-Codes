#include<iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;
    if(a==0)
    {
        cout<<"yes";
        return 0;
    }

    if(a%3==0)
    {
        cout<<"yes"<<endl;
    }
    else if((a/3)%2!=0&&a%3==1)
    {
        cout<<"no"<<endl;
    }
    else if((a/3)%2==0&&a%3==1)
    {
        cout<<"yes"<<endl;
    }
    else
        {
            cout<<"no"<<endl;
        }

    return 0;
}
