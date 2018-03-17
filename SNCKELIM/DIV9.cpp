#include<bits/stdc++.h>
using namespace std;

char str[110000];

int min1(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int max1(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    int test,i,j,k;
    int n;
    int sum=0;
    int min_v,max_v;
    int x;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        n=strlen(str);

        if(n==1&&str[0]-'0'==0)
        {
            printf("0\n");
            continue;
        }

        sum=0;
        min_v=0;
        max_v=0;

        for(j=0;j<n;j++)
        {
            x=str[j]-'0';

            min_v+=9-x;
            if(j==0){


                max_v+=x-1;
                sum=(sum+x)%9;
                continue;
            }

            max_v+=x;

            sum=(sum+x)%9;
        }

        if(sum>(9-sum))//7 2
        {
           if(min_v>=(9-sum))
           {
               printf("%d\n",9-sum);
           }
           else
           {
               printf("%d\n",sum);
           }
        }
        else if((9-sum)>sum)//2 7
        {
            if(max_v>=sum)
            {
                printf("%d\n",sum);
            }
            else
            {
                 printf("%d\n",9-sum);
            }
        }
    }

    return 0;
}











