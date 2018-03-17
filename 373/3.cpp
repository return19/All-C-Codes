#include<bits/stdc++.h>
using namespace std;

char s[1010000];

int main()
{
    int i,j,k;
    int n;
    int t;
    int d=-1;

    scanf("%d%d",&n,&t);
    scanf("%s",s);

    for(i=0;i<n;i++){
        if(s[i]=='.'){
            d=i;
            break;
        }
    }

    if(t==0 || d==-1){
        printf("%s\n",s);
        return 0;
    }

    int f=0;

    for(i=d+1;i<n;i++){
        if(s[i]-'0' >= 5){
            f=1;
            break;
        }
    }

    if(f){
        while(i!=d && t!=0){
            if(s[i]-'0' >= 5 && i-1 >d){
                s[i-1]++;
                t--;
            } else if(s[i]-'0' < 5){
                break;
            } else if(s[i]-'0' >=5 && i-1==d){
                i=d-1;
                while(i>=0 && s[i]=='9'){
                    s[i]='0';
                    i--;
                }

                if(i<0){
                    printf("1");
                    for(i=0;i<d;i++)
                        printf("%c",s[i]);
                } else {
                    s[i]++;
                    for(i=0;i<d;i++)
                        printf("%c",s[i]);
                }
                return 0;
            }
            i--;
        }

        for(j=0;j<=i;j++){
            printf("%c",s[j]);
        }
        return 0;
    }

    printf("%s\n",s);
    return 0;
}

















