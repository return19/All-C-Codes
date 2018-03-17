#include<iostream>
#include<cmath>
using namespace std;
long long power,j,ret;
long long calc(long long num)
{

    if(num==0)
        return -1;
    else if(num==1)
        return 1;
    else if(num==2)
        return 8;
    else
    {
        power=1;
        for(j=1;j<=num;j++)
        {
            power=(power*3)%1000000007;
        }

        return (2*(calc(num-1)%1000000007)+3*(calc(num-2)%1000000007)+power%1000000007)%1000000007;

    }
}

int main()
{
    int test,i;
     long long num;
    long long sal;

    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>num;
        sal=calc(num)%1000000007;

        cout<<sal<<endl;
    }
    return 0;
}
