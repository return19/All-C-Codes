#include<bits/stdc++.h>
using namespace std;

char str[101000];

int main()
{
    int i,j,k;
    int n;

    scanf("%d%d",&n,&k);
    scanf("%s",str);
    int st=0;
    int a=0,b=0,ans=0;

    for(i=0;i<n;i++){
        if(str[i]=='a')
            a++;
        else
            b++;

        if(a>k && b>k){
            while(st<n && a>k && b>k){
                if(str[st]=='a')
                    a--;
                else
                    b--;
                st++;
            }
        }

        ans=max(ans,i-st+1);
    }

    printf("%d\n",ans);

    return 0;
}

