#include<bits/stdc++.h>
using namespace std;

long long arr[110],ARR;

long long count1;

long long power_lower(long long n)
{
    long long i,c2=0;
    long long x=2,prev=0;
    count1=0;
    while(n>count1)
    {
        prev=count1;
        count1=count1+(x);
        c2++;
        x=x*2;
    }
    count1=prev;
    return (c2);
}



int main()
{
    long long test,i,j,k;
    long long bin,temp;
    long long n;
    long long lp;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memset(arr,0,sizeof(arr));

        scanf("%lld",&n);

        lp=power_lower(n);
        //cout<<" lp : "<<lp<<endl;
        //cout<<"count1 : "<<count1<<endl;
        n=n-count1-1;

        temp=n;

        ARR=-1;
        while(temp>0)
        {
            arr[++ARR]=temp%2;
            temp=temp/2;
        }



        for(j=lp-1;j>=0;j--)
        {
            if(arr[j]==1)
                cout<<6;
            else
                cout<<5;
        }
        cout<<endl;

    }
    return 0;
}













