#include<bits/stdc++.h>
using namespace std;

char n1[110000];
char n2[110000];

int main()
{
    int test,i,j,k;

    int l1,l2;

    scanf("%d",&test);

    for(k=0;k<test;k++)
    {
        scanf("%s",n1);
        scanf("%s",n2);

        l1=strlen(n1);
        l2=strlen(n2);

        int c=0,ans=0;

        for(i=l1-1 , j=l2-1 ; i>=0&&j>=0 ; i--,j--)
        {
            if(n1[i]-'0'+n2[j]-'0'+c>=10)
            {
                c=1;
                ans++;
            }
            else
            {
                c=0;
            }
        }

        while(i>=0)
        {
            if(n1[i]-'0'+c>=10)
            {
                c=1;
                ans++;
            }
            else
            {
                c=0;
            }

            i--;
        }

        while(j>=0)
        {
            if(n2[j]-'0'+c>=10)
            {
                c=1;
                ans++;
            }
            else
            {
                c=0;
            }

            j--;
        }

        if(ans==0)
        {
            printf("No carry operation\n",ans);
        }
        else if(ans==1)
        {
            printf("%d carry operation\n",ans);
        }
        else
        {
            printf("%d carry operations\n",ans);
        }

       // printf("%d\n",ans);
    }

    return 0;
}
