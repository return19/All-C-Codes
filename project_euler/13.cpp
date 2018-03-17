#include<bits/stdc++.h>
using namespace std;

long long arr[1010][51];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++){
        for(j=0;j<50;j++)
            scanf("%1lld",&arr[i][j]);
    }

    long long sum=0;
    for(i=49;i>=10;i--){
        for(j=0;j<n;j++)
            sum+=arr[i][j];
        sum/=10;
    }

    long long ans=0;

    for(i=0;i<n;i++){
        long long temp=0;
        for(j=0;j<10;j++)
            temp = temp*10 + arr[i][j];
        ans = ans + temp;
    }

    ans = ans + sum;

    long long num=0,temp = ans;
    while(temp)
    {
        temp/=10;
        num++;
    }
    while(num>10)
    {
        ans/=10;
        num--;
    }

    printf("%lld\n",ans);
    return 0;
}















