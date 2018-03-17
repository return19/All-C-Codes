#include<bits/stdc++.h>
using namespace std;

char s[1010000];

int main()
{
    long long i,j,k;
    long long l=0,r=0,p;
    long long n;

    scanf("%s",s);
    n=strlen(s);

    for(i=0;i<n;i++)
        if(s[i]=='^')
            p=i;
    for(i=0;i<n;i++){
        if(s[i]=='=')
            continue;
        else{
            if(i<p){
                l += (s[i]-'0')*(p-i);
            }else{ // i>p
                r += (s[i]-'0')*(i-p);
            }
        }
    }

    if(l==r){
        printf("balance\n");
    }else if(l>r){
        printf("left\n");
    }else{
        printf("right\n");
    }

    return 0;
}
