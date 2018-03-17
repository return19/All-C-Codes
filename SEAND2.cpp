#include<bits/stdc++.h>
using namespace std;
char a[1010];
int main()
{
    int test,n,i,j,b,len;


    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%s",a);
        len=strlen(a);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&b);
        }
        for(j=len-1;j>=0;j--)
            printf("%c",a[j]);
        printf("\n");
    }

    return 0;
}







