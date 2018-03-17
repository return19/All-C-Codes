#include<iostream>
using namespace std;

int main()
{
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        n=(3*n+n*n)/2;
        cout<<n<<endl;
    }
    return 0;
}
