#include<stdio.h>
#include<string.h>

char a[100150];

int main()
{
    long long t,i,j,flag;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%s",a);
        j=strlen(a)-1;
        flag=0;
        for(i=0;i<j;)
        {
            if(flag<2)
            {
               if(a[i]==a[j])
               {
                   i++;
                   j--;
               }
               else if(a[i]==a[j-1])
               {
                   flag++;
                   i++;
                   j-=2;
               }
               else if(a[i+1]==a[j])
               {
                   flag++;
                   i+=2;
                   j--;
               }
               else
               {
                   flag=3;
                   break;
               }

            }
            else
                break;
        }

        if(flag<2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
