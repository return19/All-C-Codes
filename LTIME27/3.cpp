#include<bits/stdc++.h>
using namespace std;

char str[110000];
char t1[110000];
char t2[110000];

int n;

int check_pal(char str1[])
{
    int i,j;

    for(i=0,j=n-2;i<j;i++,j--)
    {
        if(str1[i]!=str1[j])
            return 0;
    }

    return 1;
}

int main()
{
    int test,i,j,k;
    int flag=0;
    int ans=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        flag=0;
        ans=0;

        scanf("%s",str);

        n=strlen(str);

        for(j=0,k=n-1;j<k;j++,k--)
        {
            if(str[j]!=str[k])
            {
                int p=-1;

                for(int x=0;x<n;x++)
                {
                    if(x==j)
                    {

                        continue;
                    }
                    else
                    {
                        t1[++p]=str[x];
                    }

                }

                t1[n-1]='\n';
                p=-1;

                for(int x=0;x<n;x++)
                {
                    if(x==k)
                    {

                        continue;
                    }
                    else
                    {
                        t2[++p]=str[x];
                    }
                }

                t2[n-1]='\n';

                int c1=check_pal(t1);
                int c2=check_pal(t2);


/*
                cout<<c1<<" "<<c2<<endl;
                cout<<t1<<endl;
                cout<<t2<<endl;*/

                if(c1||c2)
                ans=1;
                else
                    ans=0;

                if(c1==1)
                {
                    int x,y,z;

                    x=j;

                    y=k+1;


                    while(y<n&&str[x]==str[y])
                    {
                        ans++;
                        y++;
                    }
                }

                if(c2==1)
                {
                    int x,y,z;

                    x=k;

                    y=j-1;

                    while(y>=0&&str[x]==str[y])
                    {
                        ans++;
                        y--;
                    }

                }

                flag=1;
                break;

            }
        }

        if(flag==1)
        {
            printf("%d\n",ans);
            continue;
        }

        int c1=0;

        j=(n-1)/2;

        k=j;
        while(k>=0&&str[k]==str[j])
        {
            c1++;
            k--;
        }

        k=j+1;

        while(k<n&&str[k]==str[j])
        {
            c1++;
            k++;
        }

        printf("%d\n",c1+1);
    }

    return 0;
}










