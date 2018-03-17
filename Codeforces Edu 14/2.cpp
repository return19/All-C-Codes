#include<bits/stdc++.h>
using namespace std;

string s;

int check(char c){
 if(c=='A' || c=='H' || c=='I' || c=='i' || c=='M'
    || c=='m' || c=='O' || c=='o'|| c=='T' || c=='U'
    || c=='V' || c=='v'|| c=='W' || c=='w' || c=='X'
    || c=='x'|| c=='Y' || c=='m')
        return 1;
    return 0;
}

int main()
{
    int i,j,k;
    cin>>s;
    int n;
    n=s.length();

    for(i=0,j=n-1;i<=j;i++,j--){
        if(i==j){
            if(check(s[i])){
                printf("TAK\n");
                return 0;
            }
            printf("NIE\n");
            return 0;
        }

        if(s[i] == s[j] && check(s[i])) continue;
        if(s[i]=='b' && s[j]=='d')  continue;
        if(s[i]=='d' && s[j]=='b')  continue;
        if(s[i]=='p' && s[j]=='q')  continue;
        if(s[i]=='q' && s[j]=='p')  continue;
        printf("NIE\n");
        return 0;
    }
    printf("TAK\n");
    return 0;
}

