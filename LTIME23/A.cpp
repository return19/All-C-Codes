#include<bits/stdc++.h>
using namespace std;

char str[1010];

int main()
{
    int test,i,j,k,n;
    int flag=0;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        flag=0;
        scanf("%s",str);
        n=strlen(str);

        if(n==2)
        {
            if(str[0]==str[1])
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
            continue;
        }

        if(n<=3)
        {
            if(str[0]==str[2])
            {
                if(str[1]==str[0])
                {
                    printf("NO\n");
                }
                else
                {
                    printf("YES\n");
                }
            }
            else
            {
                printf("NO\n");
            }
            continue;
        }

        j=3;

        flag=1;

        for(j=0;j<=n-4;j++)
        {
            if((str[j]!=str[j+2])||(str[j+1]!=str[j+3])||(str[j]==str[j+1]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
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












