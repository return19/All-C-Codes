#include<bits/stdc++.h>
using namespace std;

char str[100110];

int main()
{
    int test,i,j,k,n;
    int count1=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        scanf("%s",str);
        n=strlen(str);

        for(j=1;j<n;j++)
        {
            if(str[j-1]=='+'&&str[j]=='+')
            {
                count1++;
                str[j]='-';
            }
            else if(str[j-1]=='-'&&str[j]=='-')
            {
                count1++;
                str[j]='+';
            }

        }
        if(count1<=(n-count1))
        {
            printf("%d\n",count1);
        }
        else
        {
            printf("%d\n",(n-count1));
        }


    }

    return 0;
}
