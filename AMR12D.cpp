#include<bits/stdc++.h>
using namespace std;

char str[15];

int main()
{
    int test,i,j,k;
    int n;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        n=strlen(str);
        int flag=0;
        for(j=0,k=n-1;j<=k;j++,k--)
        {
            if(str[j]!=str[k])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
