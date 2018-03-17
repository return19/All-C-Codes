#include<bits/stdc++.h>
using namespace std;

char str[501000];
char cnt[300];
int n;

int main()
{
    int i,j,k;
    int ans=0;

    scanf("%d",&n);
    scanf("%s",str);

    for(i=0;i<2*n-2;i++)
    {
        cnt[str[i]-'a' + 'A']++;
        i++;

        if(cnt[str[i]]==0){
            ans++;

        }
        else
            cnt[str[i]]--;
    }

    printf("%d\n",ans);
    return 0;
}
