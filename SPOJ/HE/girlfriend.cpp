#include<iostream>
#include<cstring>
using namespace std;
char demand[100000];
int len;
long a,b;

/*inline int charAtPos(long pos)
{
    pos=pos%len;
    return demand[pos];
}*/
int main()
{
    int test,i;
    cin>>demand;
    len=strlen(demand);
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>a;
        cin>>b;

        if(demand[(a-1)%len]==demand[(b-1)%len])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }

    }
    return 0;
}
