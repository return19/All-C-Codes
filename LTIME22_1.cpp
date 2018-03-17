#include<bits/stdc++.h>
using namespace std;

long long arr[10000100];

int main()
{
    long long test,i,j,k,n,l;

    long long temp;
    long long m;
    scanf("%lld",&test);

    for(j=0;j<test;j++)
    {
        scanf("%lld%lld%lld",&n,&k,&l);

        temp=l-1;

        for(i=n-1;i>=0;i--)
        {
            if(l<=0)
            {
                arr[i]=1;
                continue;
            }
            m=temp%k;
            temp=temp/k;
            arr[i]=m+1;
        }

        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    return 0;
}
