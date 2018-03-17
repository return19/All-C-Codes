#include<stdio.h>
#include<string.h>

char s[100100];
char temp[100100];

long long pal_chk(char c[],long long n)
{
    long long i,j;
    for(i=0,j=n-1;i<=j;i++,j--)
    {
        if(c[i]!=c[j])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long test,i,j,k,n,x,flag=0,y,z,check1,check2;

    scanf("%lld",&test);

    for(k=0;k<test;k++)
    {
        flag=0;
        scanf("%s",s);

        n=strlen(s);

        for(i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                for(x=0,z=0;x<n;x++)
                {
                    if(x!=i)
                    {
                        temp[z]=s[x];
                        z++;
                    }
                }
                check1=pal_chk(temp,n-1);
                for(x=0,z=0;x<n;x++)
                {
                    if(x!=j)
                    {
                        temp[z]=s[x];
                        z++;
                    }
                }
                check2=pal_chk(temp,n-1);

                if((check1==0)&&(check2==0))
                {
                    flag=1;
                    printf("NO\n");
                    break;
                }
                else
                {
                    flag=1;
                    printf("YES\n");
                    break;
                }
            }
        }
        if(flag!=1)
            printf("YES\n");
    }
    return 0;
}






