#include<stdio.h>
#include<string.h>
char s[100010];

int main()
{
    int test,i,j,k,n,flag=0,x;

    scanf("%d",&test);

    for(k=0;k<test;k++)
    {
        flag=0;x=1;
        scanf("%s",s);
        n=strlen(s);
        for(i=0,j=n-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                if(flag==1)
                {
                    x=0;
                    break;
                }
                else
                {
                    flag=1;
                    if(s[i+1]==s[j])
                    {
                        i++;
                    }
                    else if(s[i]==s[j-1])
                    {
                        j--;
                    }
                    else
                    {
                        x=0;
                        break;
                    }
                }
            }
        }
        if(x==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
