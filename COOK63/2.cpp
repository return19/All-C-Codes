#include<bits/stdc++.h>
using namespace std;

char str[110][110];

int LCSubStr(char *X, char *Y, int m, int n,int &st)
{
    int LCSuff[m+1][n+1];
    int result = 0;

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                //result = max(result, LCSuff[i][j]);

                if(result<LCSuff[i][j])
                {
                    result=LCSuff[i][j];
                    st=i-LCSuff[i][j];
                }
                else if(result==LCSuff[i][j])
                {
                    int ans=0;

                    for(int z=0;z<result;z++)
                    {
                        if(X[st+z]>X[i-result+z])
                        {
                            ans=1;
                            break;
                        }
                    }

                    if(ans==1)
                    {
                        st=i-result;
                    }
                }
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}

char temp[110];

int main()
{
    int test,t,i,j,k;
    int n;

    int l1,l2;

    int mx;
    int temp1;
    int st;
    int ans;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%s",str[i]);

        l1=strlen(str[0]);

        for(i=0;i<l1;i++)
            temp[i]=str[0][i];
        temp[l1]='\0';

        mx=INT_MIN;
        ans=0;

        for(i=1;i<n;i++)
        {
            st=0;
            temp1=LCSubStr(temp,str[i], strlen(temp),strlen(str[i]),st);

            cout<<temp<<" "<<temp1<<" "<<st<<endl;

            if(mx<temp1)
            {
                mx=temp1;
                ans=st;
            }
            else if(mx==temp1)
            {
                int f=0;

                for(int z=0;z<mx;z++)
                {
                    if(temp[z]>temp[st+z])
                    {
                        f=1;
                        break;
                    }
                }

                if(f==1)
                {
                    ans=st;
                }
            }

            for(j=0;j<mx;j++)
                temp[j]=temp[ans+j];
            temp[mx]='\0';

            cout<<temp<<endl;
        }

        printf("%s\n",temp);
    }

    return 0;
}







