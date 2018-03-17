#include<bits/stdc++.h>
using namespace std;
unsigned long long m;
char str[100000010];
unsigned long long power(unsigned long long x,unsigned long long y)
{
    unsigned long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return ((temp*temp)%m);
    else
        return ((((x*temp)%m)*temp)%m);
}

int main()
{
    unsigned long long test,i,j,k,sum,n,a,b;
    char temp;
    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        sum=1;
        scanf("%llu",&m);
        scanf("%s",str);
        n=strlen(str);

        for(j=0;j<n;)
        {
            a=0;
            while(str[j]!='*')
            {
                a=a*10+str[j]-48;
                j++;
            }
            j=j+2;

            b=0;
            while(str[j]!='*'&&j<n)
            {
                b=b*10+str[j]-48;
                j++;
            }
            j++;
           // cout<<"a "<<a<<" b "<<b<<endl;
            sum=(sum*power(a,b))%m;
        }

        printf("%llu\n",sum);
    }

    return 0;
}
