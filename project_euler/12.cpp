#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long cur[101000];

long long s[101000];
vector<long long> p;

void sieve(){
    long long i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=100000;i++)
    {
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=100000;j+=i)
                s[j]=1;
        }
    }
}

int main()
{
    long long i,j,k;
    sieve();

    for(i=1;i<=41040;i++)
        arr[i] = arr[i-1]+i;

    for(i=0;i<=41040;i++){
        long long c=1,temp = arr[i];
        for(j=0;p[j]*p[j]<=temp;j++){
            long long t=0;
            while(temp%p[j]==0)
            {
                temp/=p[j];
                t++;
            }
            c = c*(t+1);
        }
        if(temp>1)
            c*=2;
        //cout<<i<<" "<<c<<endl;
        cur[i]=c;
    }
   // for(i=0;i<10;i++)
       // cout<<arr[i]<<" "<<cur[i]<<endl;

    long long test,t;
    long long n;
    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);

        for(i=1;i<=41040;i++){
            if(cur[i]>n)
                break;
        }
        cout<<arr[i]<<endl;
    }

    return 0;
}
