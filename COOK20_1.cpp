#include<bits/stdc++.h>
using namespace std;

char str[10010],n;
map<char,int> memo;
int main()
{
    int test,i,j,k,flag=0;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        scanf("%s",str);
        j=0;
        n=strlen(str);
        if(n%2!=0)
        {
            printf("NO\n");
            continue;
        }
        for(j=0;j<n;j++)
        {
            memo[str[j]]++;
        }
        flag=0;
        for(k=0;k<j;k++)
        {
            if(memo[str[k]]==(n-memo[str[k]]))
            {
                printf("YES\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }

    }

    return 0;
}
