#include<bits/stdc++.h>
using namespace std;

char str1[110];
char str2[110];

int main()
{
    int test,i,j,k;
    int n1,n2;

    scanf("%d",&test);

    int ans=0;

    for(i=0;i<test;i++)
    {
        ans=1;
        scanf("%s",str1);
        scanf("%s",str2);

        n1=strlen(str1);
        n2=n1;

        j=0;
        k=0;

        while(j<n1&&k<n2)
        {
            if(str1[j]=='?'||str2[k]=='?')
            {
                j++;
                k++;
                continue;
            }

            if(str1[j]==str2[k])
            {
                j++;
                k++;
                continue;
            }

            ans=0;
            break;
        }

        if(ans==0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }

    }

    return 0;
}
