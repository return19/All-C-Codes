#include<bits/stdc++.h>
using namespace std;

long long solve(long long x){
   // cout<<x<<endl;
    if(x==1)
        return 1;
    if(x&1)
        return 1 + solve(3*x+1);
    return 1 + solve(x/2);
}

long long arr[5010000];
long long val[5010000];

int main()
{
    long long i,j,k;
    long long test,t,n;

    arr[1] = 1;
    val[1] = 1;
    for(i=2;i<=5000000;i++)
    {
        long long temp = solve(i);
        if(temp>=val[i-1]){
            val[i] = temp;
            arr[i] =  i;
        } else {
            val[i] = val[i-1];
            arr[i] = arr[i-1];
        }
    }

    //for(i=1;i<=12;i++)
      //  cout<<i<<" "<<val[i]<<" "<<arr[i]<<endl;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);
        printf("%lld\n",arr[n]);
    }

    return 0;
}
