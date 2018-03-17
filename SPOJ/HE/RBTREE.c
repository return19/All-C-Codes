#include<stdio.h>
int f=1;
int main()
{
    int test,i,j,p1,p2,x,y,sum=0;
    char inp[10];

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",inp);

        if(inp[1]=='i')
        {
            if(f==0)
            {
                f=1;
            }
            else
            {
                f=0;
            }
        }
        else if(inp[1]=='r')
        {
            scanf("%d%d",&x,&y);
            p1=2;
            p2=1;   sum=0;
            for(j=x;j<=y;j++)
            {
                while(p1<=j)
                {
                    p2++;
                    p1=p1*2;
                }
                p1=p1/2;
                p2--;
                if(f==1)
                {
                    if(p2%2!=0)
                    {
                        sum++;
                    }
                }
                else
                {
                    if(p2%2==0)
                    {
                        sum++;
                    }
                }
            }
            printf("%d\n",sum);
        }
        else
        {
            scanf("%d%d",&x,&y);
            p1=2;
            p2=1;
            sum=0;
            for(j=x;j<=y;j++)
            {
                while(p1<=x)
                {
                    p2++;
                    p1=p1*2;
                }
                p1=p1/2;
                p2--;
                if(f==1)
                {
                    if(p2%2==0)
                    {
                        sum++;
                    }
                }
                else
                {
                    if(p2%2!=0)
                    {
                        sum++;
                    }
                }
            }
            printf("%d\n",sum);
        }
    }

    return 0;
}









