#include<bits/stdc++.h>
using namespace std;

map<char,int> memo;
char str[100010];

int main()
{
    int test,i,j,count1=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);
        memo.clear();
        j=0;
        while(str[j]!='\0')
        {
            memo[str[j]]++;
            j++;
        }
        scanf("%s",str);
        j=0;
        count1=0;
        while(str[j]!='\0')
        {
            if(memo[str[j]])
            {
                count1++;
            }
            j++;
        }

        printf("%d\n",count1);
    }
    return 0;
}
