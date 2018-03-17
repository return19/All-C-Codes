#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *in,*out;
    char s[100],a[100],ch;
    int i=0;
    in=fopen("one.txt","w");
    scanf("%[^$]s",s);
    fputs(s,in);
    fclose(in);
    out=fopen("one.txt","r");


     ch=getc(out);
     i=0;
    while(ch!=EOF)
    {
        a[i++]=ch;
        ch=getc(out);
    }
    a[i]='\0';

    for(i=0;i<strlen(a);i++)
    {
        a[i]=tolower(a[i]);
    }
    a[0]=toupper(a[0]);
    for(i=1;i<strlen(a);i++)
    {
        if((a[i-1]==' ')||(a[i-1]=='\n'))
        {
            a[i]=toupper(a[i]);
        }
    }
    fclose(out);
    out=fopen("one.txt","w");
    fputs(a,out);
    fclose(out);
    out=fopen("one.txt","r");
    ch=getc(out);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=getc(out);
    }


    fclose(out);
    return 0;
}
