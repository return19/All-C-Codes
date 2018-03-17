#include<iostream>
using namespace std;

int main()
{
    long long index,i,a,b,temp;
    int test,x[112];

    cin>>test;

    for(i=0;i<test;i++)
    {
        cin>>a;
        cin>>b;
        index=0;
        a=a%10;
        if(b==0)
        {
            cout<<1<<endl;
            continue;
        }
        x[0]=a;
        temp=a;
        temp=(a*temp)%10;
        while(temp!=x[0])
        {
            x[++index]=temp;
            temp=(a*temp)%10;
        }
        index++;
        if(b%index==0)
         cout<<x[index-1]<<endl;
         else
            cout<<x[b%index-1]<<endl;
    }
    return 0;
}
