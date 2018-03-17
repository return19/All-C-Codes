#include<bits/stdc++.h>
using namespace std;

char n[101000];
char m[110];

int lps[110];

void compLps(){
    int l = strlen(m);
    int i,j,k;
    int len=0;
    lps[0]=0;

    i=1;
    while(i<l){
        if(m[i]==m[len]){
            len++;
            lps[i]=len;
            i++;
        }else {
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp(){
    compLps();

    int i,j,k;

    int ln = strlen(n);
    int lm = strlen(m);

    for(i=0;i<lm;i++)
        cout<<lps[i]<<" ";
    cout<<endl;

    i=0;
    j=0;
    while(i<ln){
        if(n[i]==m[j]){
            i++;
            j++;
        }
        if(j==lm){
            cout<<"Found at : "<<i-j<<endl;
            j = lps[j-1];
        }else if(i<ln && n[i]!=m[j]) {
            if(j==0){
                i++;
            } else{
                j = lps[j-1];
            }
        }
    }
}

int main()
{
    scanf("%s%s",n,m);
    kmp();
    return 0;
}
