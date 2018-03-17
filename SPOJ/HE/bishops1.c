#include<stdio.h>
#include<string.h>
int main()
{
    char n[210];
    int temp,br,i,j,len;

    for(i=0;i<1024;i++)
    {
        scanf("%s",n);
        len=strlen(n);
        if(len==1&&n[0]=='1')
        {
            printf("1\n");
            continue;
        }
        if(n[len-1]-48==0)
        {
            j=len-1;
            while(n[j]-48==0)
            {
                n[j]=48+9;
                j--;
            }
            n[j]=n[j]-1;
        }
        else
        {
            n[len-1]-=1;
        }
        br=0;
        for(j=len-1;j>=0;j--)
        {
            temp=(n[j]-48)*2+br;
            br=temp/10;
            n[j]=48+temp%10;
        }


            for(j=0;n[j]!='\0';j++)
            {
                if(n[j]!=0)
                {
                    break;
                }
            }
            if(br!=0)
            printf("%d",br);
            while(n[j]!='\0')
            {
                printf("%c",n[j]);
                j++;
            }
        printf("\n");
    }
    return 0;
}
