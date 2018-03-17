#include<bits/stdc++.h>
using namespace std;

char str[10];

long long val[10];

void init()
{
    val[0]=1;
    val[1]=20;
    val[2]=360;
    val[3]=360*20;
    val[4]=360*20*20;
    val[5]=360*20*20*20;
    val[6]=360*20*20*20*20;
    val[7]=360*20*20*20*20*20;
}

int main()
{
    long long n,i,j,k,sum,tsum;
    char sacr;
    init();

    scanf("%lld",&n);
    sacr=getchar();


    while(n!=0)
    {
        tsum=0;

        for(i=n;i>0;i--)
        {
            scanf("%[^\n]s",str);
            sacr=getchar();
            j=0;
            sum=0;
            while(str[j]!='\0')
            {
                if(str[j]=='.')
                {
                    sum=sum+1;
                }
                else if(str[j]=='-')
                {
                    sum=sum+5;
                }
                else if(str[j]=='S')
                {

                }

                j++;
            }

            tsum=tsum+sum*val[i-1];
        }

        printf("%lld\n",tsum);

        scanf("%lld",&n);
        sacr=getchar();
    }

    return 0;
}
