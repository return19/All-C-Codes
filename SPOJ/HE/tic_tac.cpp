#include<iostream>
using namespace std;

int main()
{
    long long test,i,num,max,min,matches,rem,div,n;

    cin>>test;//%1000000007
    for(i=0;i<test;i++)
    {
        cin>>num;
        n=num-1;
        max=((n*(n+1)*(2*n+1))/6)%1000000007;
        matches=((num*(num-1))/2);
        rem=matches%num;
        div=matches/num;
        min=(((num-rem)%1000000007)*((div*div)%1000000007)+rem*(((div+1)*(div+1))%1000000007)%1000000007)%1000000007;

        cout<<min<<" "<<max<<endl;
    }
    return 0;

}
