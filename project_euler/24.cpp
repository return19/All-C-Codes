#include<bits/stdc++.h>
using namespace std;

int fact[21];
int vis[21];
int ans[21];

int main()
{
    int i,j,k;

    fact[0]=0;
    fact[1]=1;
    for(i=2;i<=13;i++)
        fact[i] = i*fact[i-1];

    int test,t;

    scanf("%d",&test);
    int n;

    for(t=0;t<test;t++){

        for(i=0;i<=12;i++)
            vis[i]=0;

        scanf("%d",&n);
        n--;

       /* char s[15] = "abcdefghijklm";
        for(i=0;i<n;i++){
            next_permutation(s,s+13);
        }
        cout<<s<<endl;*/

        for(i=0;i<=12;i++){
            int cur=0;
            while(n && n>=fact[12-i]){
                n-= fact[12-i];
                cur++;
                //cout<<n<<endl;
            }

            for(j=0;j<13;j++){
                if(cur==0 && !vis[j])
                {
                    ans[i]=j;
                    vis[j]=1;
                    break;
                }
                if(!vis[j]){
                    cur--;
                }
            }
        }

        for(i=0;i<13;i++)
            printf("%c",ans[i]+'a');
        printf("\n");
    }

    return 0;
}


















