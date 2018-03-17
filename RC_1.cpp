#include<bits/stdc++.h>
using namespace std;

char str[10010];

int main()
{
    long long test,i,j,k,sum=0;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);
        j=0;    sum=0;
        while(str[j]!='\0')
        {
            sum=sum+(str[j]-97+1);
            j++;
        }

        printf("%lld\n",sum);
    }
    return 0;
}
