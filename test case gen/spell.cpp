#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[101000];

int main()
{
    freopen("input05.txt","r",stdin);
    freopen("output05.txt","w",stdout);
    long long i,j,k;
    int test,t;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        long long f=0;

        for(i=0;i<n;i++){
            while(arr[i]%2==0)
                arr[i]/=2;
            while(arr[i]%3==0)
                arr[i]/=3;
            while(arr[i]%5==0)
                arr[i]/=5;
            if(i){
                if(arr[i]!=arr[i-1]){
                    f=1;
                    printf("No\n");
                    break;
                }
            }
        }

        if(!f){
            printf("Yes\n");
        }
    }

    return 0;
}










