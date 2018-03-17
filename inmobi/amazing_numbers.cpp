#include<bits/stdc++.h>
using namespace std;

int c[10];

int main()
{
    int test,i,j,k,t;

    int n,x;

    int temp;

    int ans=0,chk;

    int num;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&x);

        ans=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);

            for(j=0;j<=9;j++)
                c[j]=0;

            chk=0;

            while(temp)
            {
                num=temp%10;

                c[num]++;

                if(c[num]==1&&num<=x)
                    chk++;

                temp /=10;
            }

            if(chk==x+1)
                ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}
