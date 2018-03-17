#include<stdio.h>
#include <string.h>

int max(int a, int b)
{   return (a > b)? a : b; }

int lcs( char *X, char *Y, int m, int n )
{
   int L[n+1][n+1];
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   return L[m][n];
}

void strrev1(char* str1)
{
    int i,j;
    int n;
    n=strlen(str1);

    for(i=0;i<n/2;i++)
    {
    	char a;


        a=str1[i];
        str1[i]=str1[n-i-1];
        str1[n-i-1]=a;
    }

    str1[n]='\0';
}

int findMinInsertionsLCS(char str[], int n)
{

   char rev[n+1];
   strcpy(rev, str);
   strrev1(rev);

   return (n - lcs(str, rev, n, n));
}

char str[1110000];

int main()
{
    int test,i,j,k;
    int n;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        scanf("%s",str);

        printf("%d\n",findMinInsertionsLCS(str,n));
    }
}
