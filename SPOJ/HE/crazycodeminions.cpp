#include<iostream>
#include<cstring>
using namespace std;

class code
{
    char a[1001];

public:
    int num_instruct()
    {
        long int t,n=0;
        for(t=1;a[t]!=NULL;t++)
        {
           if(a[t]<a[t-1])
           {
               n=n-a[t-1]+a[t]+26;
           }
           else
           {
               n=n+a[t]-a[t-1];
           }
        }
        return n;
    }
    void input()
    {cin>>a;
    }

    int len()
    {
        return strlen(a);
    }
    int diff(int n2,int n1)
    {
        int i=n2-n1;
        if(i<0)
        {
            i=i*(-1);
        }
        return i;
    }


};

int main()
{
 code t[101];
 int t1;
 cin>>t1;
 int i;
 for(i=0;i<t1;i++)
        t[i].input();

 for(i=0;i<t1;i++)
 {

     if(t[i].num_instruct()+t[i].len()+1<11*t[i].len())
     {
         cout<<"YES"<<endl;
     }
     else
     {
         cout<<"NO"<<endl;
     }
 }
 return 0;
}




