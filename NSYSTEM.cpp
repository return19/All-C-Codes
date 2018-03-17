#include<bits/stdc++.h>
using namespace std;

char a[10];
char b[10];

char str[10];

int valof(char x)
{
    if(x=='m')
        return 1000;
    else if(x=='c')
        return 100;
    else if(x=='x')
        return 10;
    else
        return 1;
}

int str_to_num(char str1[])
{
    int i,j,k,ans=0;
    int pres=1;

    i=0;
    while(str1[i]!='\0')
    {
        if(str1[i]>=48&&str1[i]<=57)
        {
            pres=str1[i]-'0';
            i++;
            continue;
        }

        ans=ans+pres*(valof(str1[i]));

        i++;
        pres=1;
    }

    return ans;

}

int main()
{
    int test,i,j,k;
    int num,temp;
    int mod;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",a);
        scanf("%s",b);

        num=str_to_num(a)+str_to_num(b);

        //cout<<"num : "<<num<<endl;

        temp=num;

        j=-1;

        mod=temp%10;

        if(mod!=0)
        {
            str[++j]='i';
            if(mod!=1)
            str[++j]='0'+mod;
        }

        temp=temp/10;
        mod=temp%10;

        if(mod!=0)
        {
            str[++j]='x';
            if(mod!=1)
            str[++j]='0'+mod;
        }

        temp=temp/10;
        mod=temp%10;

        if(mod!=0)
        {
            str[++j]='c';
            if(mod!=1)
            str[++j]='0'+mod;
        }
        temp=temp/10;
        mod=temp%10;
        if(mod!=0)
        {
            str[++j]='m';
            if(mod!=1)
            str[++j]='0'+mod;
        }

        for(k=j;k>=0;k--)
        {
            printf("%c",str[k]);
        }
        printf("\n");

    }

    return 0;
}











