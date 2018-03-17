#include<bits/stdc++.h>
using namespace std;

char str[10010];
map<char,int> memo;
map<char,int> vis;
map<char,int> last;
map<char,int> count1;
int main()
{
    int test,i,j,k,n;
    int max1;
    scanf("%d",&test);
    memo.clear();
    vis.clear();
    last.clear();
    count1.clear();
    for(i=0;i<test;i++)
    {
        max1=-999999;
        scanf("%s",str);
        n=strlen(str);

        for(j=0;j<n;j++)
        {
            count1[str[j]]++;
            if(memo[str[j]]==0)
            {
                memo[str[j]]=j+1;
                vis[str[j]]=1;
                continue;
            }

            if(j+1-memo[str[j]]>max1&&count1[str[j]]!=3)
                max1=j+1-memo[str[j]];
            else if(j-memo[str[j]]>max1)
            {
                max1=j-memo[str[j]];
            }
            if(vis[str[j]]==1)
            {
                last[str[j]]=j+2;
                vis[str[j]]=2;
            }
            else if(vis[str[j]]==2)
            {
                memo[str[j]]=last[str[j]];
                last[str[j]]=j+2;
                vis[str[j]]=2;
            }

        }
        /*for(j=0;j<n;j++)
        {
            if(max1<n-memo[str[j]])
                max1=n-memo[str[j]];
        }*/
        printf("%d\n",max1);
    }
    return 0;
}
