#include<stdio.h>
#include<string.h>

int main()
{
    char n[210];
    int br,i,l,j,temp;

    for(i=0;i<1024;i++)
    {
        br=0;
        temp=0;
        scanf("%s",n);
        l=strlen(n);
        if(l==1&&n[0]=='1')
        {
            printf("1\n");
            continue;
        }
        n[l-1]=n[l-1]-1;
        for(j=l-1;j>=0;j--)
        {
            n[j]=n[j]+br;
            temp=(n[j]-48)*2;
            br=temp/10;
            temp=temp%10;
            printf("%d",temp);
        }
        if(br!=0)
        {
            printf("%d",br);
        }
        printf("\n");
    }
}
