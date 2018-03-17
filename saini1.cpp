#include<bits/stdc++.h>
using namespace std;

char str[101000];
char str2[101000];

int main()
{
    int t,test,i,j,k;
    int n;

    int e1,e2;
    int ans=0;
    int u=0,s=0;
    int temp;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",str);

        n=strlen(str);
        ans=INT_MAX;
        u=0;    s=0;

        for(i=0;i<n;i++)
        {
            if(str[i]=='U')
                u++;
            else
                s++;
        }

        if(abs(u-s)>=2){
            printf("-1\n");
            continue;
        }

        if(s==u)
        {
            temp=0;
            for(i=0;i<n;i=i+2)
            {
                str2[i]='S';
                str2[i+1]='U';
            }

            for(i=0;i<n;i++)
            {
                if(str[i]!=str2[i])
                    temp++;
            }

            ans=min(ans,temp/2);

            temp=0;
            for(i=0;i<n;i=i+2)
            {
                str2[i]='U';
                str2[i+1]='S';
            }

            for(i=0;i<n;i++)
            {
                if(str[i]!=str2[i])
                    temp++;
            }
            ans=min(ans,temp/2);
        }
        else if(s>u)
        {
            temp=0;
            for(i=0;i<n;i=i+2)
            {
                str2[i]='S';
                str2[i+1]='U';
            }

            for(i=0;i<n;i++)
            {
                if(str[i]!=str2[i])
                    temp++;
            }
            ans=min(ans,temp/2);
        }
        else
        {
            temp=0;
            for(i=0;i<n;i=i+2)
            {
                str2[i]='U';
                str2[i+1]='S';
            }

            for(i=0;i<n;i++)
            {
                if(str[i]!=str2[i])
                    temp++;
            }
            ans=min(ans,temp/2);
        }

        printf("%d\n",ans);
    }

    return 0;
}
















