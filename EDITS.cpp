#include<bits/stdc++.h>
using namespace std;
int table[2051][2051];
char str1[2050],str2[2050];
int n1,n2;

int min1(int x,int y)
{
    if(x>y)
        return y;
    else
        return x;
}
int min3(int x,int y,int z)
{
    return min1(min1(x,y),z);
}

int edit()
{
    int i,j,temp;
    int left,up,cor;
    for(i=0;i<=n1;i++)
        table[i][0]=i;
    for(i=0;i<=n2;i++)
        table[0][i]=i;

    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            left=table[i][j-1]+1;
            up=table[i-1][j]+1;
            cor=table[i-1][j-1];
            temp=(str1[i-1]!=str2[j-1]);
            cor=cor+temp;
            table[i][j]=min3(left,up,cor);
        }
    }
    return table[n1][n2];
}

int main()
{
    int test,i,j,ans;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%s",str1);
        scanf("%s",str2);

        n1=strlen(str1);
        n2=strlen(str2);

        ans=edit();
        printf("%d\n",ans);
    }
    return 0;
}















