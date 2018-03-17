#include<bits/stdc++.h>
using namespace std;

char str[1000010],n;

int main()
{
    long long test,i,j,k,lim=1,days=0;
    long long count1=1;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        lim=1;
        days=0;
        scanf("%s",str);
        n=strlen(str);

        for(j=0;j<n;j++)
        {
            if(str[j]=='.')
            {
                count1=1;
               while(str[j]=='.')
               {

                   count1++;
                   j++;
               }
               if(count1>lim)
               {
                   days++;
                   lim=count1;
               }
               j--;

            }
        }
        printf("%lld\n",days);
    }

    return 0;
}
