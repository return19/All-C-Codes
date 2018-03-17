#include<iostream>
using namespace std;
int main()
{
    int a[10],count1=0;
    cout<<"Enter the numbers:";
    for(int i=0;i<10;i++)
    {cin>>a[i];
    count1++;
        if(a[i]==42)
        {count1--;
            break;
        }

    }
    for(int i=0;i<count1;i++)
    {
        cout<<endl<<a[i]<<endl;
    }
    return 0;
}
