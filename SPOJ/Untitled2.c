#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"Enter the numbers:";
    for(int i=0;i<10;i++)
    {cin>>a[i];

        if(a[i]==42)
        {
            break;
        }

    }
    for(int i=0;i<3;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
