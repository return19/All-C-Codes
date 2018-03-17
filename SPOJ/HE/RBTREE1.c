#include<stdio.h>
long long f=1;
long long check(long long num,long long color) //1 for red and 0 for black
{
    long long p1,p2;
    p1=2;
    p2=1;
    if(color==1)
    {
                while(p1<=num)
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
                        return 1;
                    }
                }
                else
                {
                    if(p2%2==0)
                    {
                        return 1;
                    }
                }
                return 0;
    }
    else
    {
                while(p1<=num)
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
                        return 1;
                    }
                }
                else
                {
                    if(p2%2!=0)
                    {
                        return 1;
                    }
                }
                return 0;
    }
}

int main()
{
    long long test,i,j,k,x,y,dif,p1,p2,lev1,lev2,temp,sum,b;
    char inp[5];
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",inp);
        if(inp[1]=='i')
        {
            if(f==1)
            {
                f=0;
            }
            else
            {
                f=1;
            }
        }
        else
        {
            if(inp[1]=='r')
                b=1;
            else
                b=0;
            scanf("%lld%lld",&x,&y);
            sum=0;
           /* if(x==y)
            {
                sum=sum+check(x,b);
                printf("%d\n",sum);
                continue;
            }*/
            if(x>y)
            {

                temp=x;
                x=y;
                y=temp;
            }

            p1=2;
            p2=1;
            while(p1<=x)
            {
                p1=p1*2;
                p2++;
            }
            p1=p1/2;
            p2--;
            lev1=p2;
             p1=2;
            p2=1;
            while(p1<=y)
            {
                p1=p1*2;
                p2++;
            }
            p1=p1/2;
            p2--;
            lev2=p2;

            if(lev1!=lev2)
            {
                for(k=0;k<(lev2-lev1);k++)
                {
                    sum+=check(y,b);
                    if(y%2==0)
                        y=y/2;
                    else
                        y=(y-1)/2;
                }
            }
            if(x==y)
            {
                sum=sum+check(x,b);
                printf("%lld\n",sum);
                continue;
            }
            while(x!=y)
            {
                sum=sum+check(x,b);
                if(x%2==0)
                    x=x/2;
                else
                    x=(x-1)/2;
                sum=sum+check(y,b);
                 if(y%2==0)
                    y=y/2;
                else
                    y=(y-1)/2;
            }
            sum=sum+check(x,b);
            printf("%lld\n",sum);
        }
    }
    return 0;
}
















