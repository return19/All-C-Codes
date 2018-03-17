#include<iostream>
using namespace std;

class fun
{
public:
    int chkprm(int n)
    {int i,flag=1;
        for(i=2;i<n/2;i++)
        {
            if(n%i==0)
            {
                flag=0;
                return flag;
            }
        }
        return flag;
    }

};

int main()
{
    int t,i,j,c;
    fun e;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        for(j=a;j<=b;j++)
        {
            c=e.chkprm(j);
            if(c==1)
                cout<<j<<endl;
        }
    }
    return 1;
}
