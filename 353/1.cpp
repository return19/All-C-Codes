#include<bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k;
    long long a,b,c;


    scanf("%lld%lld%lld",&a,&b,&c);

    if(a==b && c==0){
        printf("YES\n");
        return 0;
    }

    if(b>=a && c>0){
        b=abs(b-a);

        if(b%c==0)
            printf("YES\n");
        else
            printf("NO\n");

    }else if(b<=a && c<0){
        b=abs(b-a);
        c=abs(c);

        if(b%c==0)
            printf("YES\n");
        else
            printf("NO\n");
    }else{
        printf("NO\n");
    }


    return 0;
}
