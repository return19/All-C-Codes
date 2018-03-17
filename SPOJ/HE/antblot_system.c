#include<stdio.h>
#include<string.h>
int main()
{
    char s[10010],x;
    long long test,sum=0,i,j,k,l;
    long long a[3];
    scanf("%d",&test);
    x=getchar();

    for(i=0;i<test;i++)
    {
        x=getchar();
        gets(s);


        sum=0; k=0;
        for(j=0;s[j]!='\0';j++)
        {
            if(s[j]==' ')
            {
                a[k]=sum;
                k++;
                j=j+2;
                sum=0;
                continue;
            }
            else if(s[j]=='m')
            {
                if(k==2)
                {
                    break;
                }
                a[k]=-1;
                k++;
                sum=0;

                while(s[j]!=' ')
                {
                    j++;
                }
                j=j+2;
                continue;
            }
            else
            {
                sum=10*sum+(s[j]-48);
                if(s[j+1]=='\0')
                {
                    a[k]=sum;
                    break;
                }
            }


        }

        if(a[0]==-1)
        {
            a[0]=a[2]-a[1];
        }
        else if(a[1]==-1)
        {
            a[1]=a[2]-a[0];
        }
        else
        {
            a[2]=a[1]+a[0];
        }
        printf("%lld + %lld = %lld\n",a[0],a[1],a[2]);
    }
    return 0;
}
