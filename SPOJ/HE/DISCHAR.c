#include<map>
using namespace std;
#include<stdio.h>

 map<int,int> memo;

 char s[100010];

int main()
{
    int test,i,n,sum;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",s);
        n=0; sum=0;
        while(s[n]!='\0')
        {
            if(memo[s[n]]==0)
            {
                memo[s[n]=1;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
