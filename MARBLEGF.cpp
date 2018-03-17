#include<bits/stdc++.h>
using namespace std;

long long bt[1010000];
long long n;

long long sum(long long idx){

    if(idx==0)
        return 0;

    long long res=0,i;
    for(i=idx;i>0;i-=(i&(-i)))
        res += bt[i];
    return res;
}

void add(long long idx,long long val){
    while(idx<=n){
        bt[idx] += val;
        idx += (idx&(-idx));
    }
}

int main(){

    long long i,j,k;
    long long q,x,y;

    scanf("%lld%lld",&n,&q);

    for(i=1;i<=n;i++){
        scanf("%lld",&x);
        add(i,x);
    }

    char s[10];

    for(i=0;i<q;i++){
        scanf("%s",s);
        scanf("%lld%lld",&x,&y);

        x++;

        if(s[0]=='S'){
            y++;
            printf("%lld\n",sum(y)-sum(x-1));
        }else if(s[0]=='G'){
            add(x,y);
        }else{ // s[0]=='T'
            add(x,-1*y);
        }
    }

    return 0;
}













