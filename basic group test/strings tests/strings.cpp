#include<bits/stdc++.h>
using namespace std;

char str[101000];

int main(){
    //freopen("input03.txt","r",stdin);
    //freopen("output03.txt","w",stdout);
    int i,j,k;
    int test,t;
    int n;
    int ans=1;
    int c=1;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%s",str);
        n = strlen(str);

        ans=1;
        c=1;

        for(i=0;i<n-1;i++){
            if(str[i]==str[i+1])
                c++;
            else
                c=1;
            ans = max(ans,c);
        }

        printf("%d\n",ans);
    }

    return 0;
}













