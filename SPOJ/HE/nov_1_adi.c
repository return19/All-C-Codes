#include<map>

using namespace std;

#include<stdio.h>
#include<string.h>

map<char,int> memo;

void main()
{
    char a[100];
    int i,t,x;

    scanf("%d",&t);

    while(t--)
    {
        gets(a);
        x=0;

        for(i=0;a[i];i++)
        {
            if(memo[a[i]]!=1)
            {
                memo[a[i]]=1;
                x++;
            }
        }

        printf("%d",x);
    }
}
