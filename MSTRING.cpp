#include<bits/stdc++.h>
using namespace std;

char str1[10100];
char str2[10100];

int n1,n2;

int dp1[1100][1100];

void lcs()
{
    int i,j,k;

    for(i=0;i<=n1;i++)
        dp1[i][0]=0;
    for(j=0;j<=n2;j++)
        dp1[0][j]=0;

    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp1[i][j]= 1+ dp1[i-1][j-1];
            else
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
        }
    }


    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
            cout<<dp1[i][j]<<" ";
        cout<<endl;
    }


}

int main()
{
    int i,j,k;

    scanf("%s",str1);
    scanf("%s",str2);

    n1=strlen(str1);
    n2=strlen(str2);

    lcs();

    return 0;
}
