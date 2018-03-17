#include<bits/stdc++.h>
using namespace std;

char str[101000];
int cnt[101000];

int main()
{
    int i,j,k;
    int test,t;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%s",str);
        scanf("%d",&k);

        int n = strlen(str);
        for(i=0;i<n;i++)
            cnt[i]=0;

        for(i=0;i<n;i++){
            if(!k) break;
            if(str[i]!='a'){
                str[i]='a';
                k--;
                cnt[i]=1;
            }
        }

        if(k!=0){
            for(i=n-1;i>=0;i--){
                if(cnt[i]==0){
                    str[i]='b';
                    k--;
                }
                if(k==0)    break;
            }
        }

        printf("%s\n",str);
    }

    return 0;
}
