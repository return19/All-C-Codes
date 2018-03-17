#include<bits/stdc++.h>
using namespace std;

char txt[101000][100];
char pat[101000];

void LPS(char *pat, int M, int *lps)
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
         {
           len = lps[len-1];

          }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

void KMP( char *txt,char *pat,int id)
{
    printf("In text pattern %d : \n",id);

    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;
    int f=0;
    LPS(pat, M, lps);

    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        printf("Pattern occurs at index %d\n", i-j);
        f=1;
        j = lps[j-1];
      }
      else if (i < N && pat[j] != txt[i])
      {

        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }

    if(f!=1)
    {
        printf("Pattern doesn't occur\n");
    }
}


int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%s",txt[i]);
    scanf("%s",pat);
    for(i=0;i<n;i++){

        KMP(txt[i],pat,i);
    }

    return 0;
}
