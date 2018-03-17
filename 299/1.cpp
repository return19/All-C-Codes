#include<bits/stdc++.h>
using namespace std;

string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string arr2[10]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    if(n<10)
    {
        cout<<arr[n]<<endl;
    }
    else if(n%10==0)
    {
        cout<<arr2[n/10 - 1]<<endl;
    }
    else if(n==11)
        cout<<"eleven"<<endl;
    else if(n==12)
        cout<<"twelve"<<endl;
    else if(n==13)
        cout<<"thirteen"<<endl;
    else if(n==14)
        cout<<"fourteen"<<endl;
    else if(n==15)
        cout<<"fifteen"<<endl;
    else if(n==16)
        cout<<"sixteen"<<endl;
    else if(n==17)
        cout<<"seventeen"<<endl;
    else if(n==18)
        cout<<"eighteen"<<endl;
    else if(n==19)
        cout<<"nineteen"<<endl;
    else
    {
        cout<<arr2[n/10 -1]<<"-"<<arr[n%10]<<endl;
    }



    return 0;
}



















