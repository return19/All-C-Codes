#include<stdio.h>
#include<string.h>
char inp[100010],pat[100010];
int inp1,pat1;
int substr_chk(int start)
{
    int i,j,k=0;
    for(i=start,j=start+pat1-1;i<=j;i++,j--)
    {
        if(inp[i]!=pat[k])
        {
            return 0;
        }
        if(inp[j]!=pat[pat1-1-k])
        {
            return 0;
        }
        k++;
    }
    return 1;
}

int main()
{
    int test,i,j,flag=0;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        flag=0;
        scanf("%s",inp);
        scanf("%s",pat);
        inp1=strlen(inp);
        pat1=strlen(pat);

        for(j=0;j<inp1-pat1+1;j++)
        {
            if(inp[j]==pat[0]&&inp[j+pat1-1]==pat[pat1-1])
            {
                if(substr_chk(j))
                {
                    printf("YES\n");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }
    }
    return 0;
}
