#include<bits/stdc++.h>
using namespace std;

char s[101000];
char t[101000];

int arr[101000];
int t_n,s_n;

bool match(char *first, char * second)
{

    if (*first == '\0' && *second == '\0')
        return true;


    if (*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;


    if (*first == *second)
        return match(first+1, second+1);

    if (*first == '*')
        return match(first+1, second) || match(first, second+1);
    return false;
}

char temp[10100];

void solve()
{
    bool f;
    int i,j,k;

    for(i=0;i<s_n;i++)
        arr[i]=-1;

    for(i=0;i<s_n;i++)
    {
        for(j=i;j<s_n;j++)
        {

            for(k=j;k<s_n;k++)
            {
                temp[k-j]=s[k];
                temp[k-j+1]='\0';

                f=match(t,temp);

              //  cout<<temp<<" "<<f<<endl;

                if(f)
                {
                    arr[i]=k;
                    break;
                }
            }

            if(arr[i]!=-1)
            {
                while(i<s_n&&i<=j)
                {
                    arr[i]=arr[j];
                    i++;
                }
                i--;

                break;
            }
        }
    }
}

int main()
{
    int i,j,k;
    int ts,test;


    int st,ed;

    scanf("%d",&test);

    for(ts=0;ts<test;ts++)
    {
        scanf("%s",t);
        scanf("%s",s);

        t_n=strlen(t);
        s_n=strlen(s);

        i=0;
        for(j=0;j<t_n;j++)
        {
            if(t[j]!='*')
            {
                t[i++]=t[j];
            }
            else
            {
                t[i++]='*';
                while(j<t_n&&t[j]=='*')
                    j++;
                j--;
            }
        }

        t[i]='\0';
        t_n=i;


            solve();

            for(i=0;i<s_n;i++){
                if(arr[i]==-1)
                {
                    printf("-1 ");
                }
                else
                    printf("%d ",arr[i]+1);
            }
            printf("\n");

    }

    return 0;
}








