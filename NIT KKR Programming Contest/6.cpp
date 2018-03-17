#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int i,j,k;
    int n;
    int q;
    int x,y;

    scanf("%d%d",&n,&q);

    cin>>s;

    for(i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        x--;
        y--;

        int ans=0;

        while(x<n && y<n && s[x]==s[y]){
            ans++;
            x++;
            y++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

