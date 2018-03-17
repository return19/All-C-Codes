#include<bits/stdc++.h>
using namespace std;

char txt[101000];
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

int KMP( char *txt,char *pat)
{
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
        //printf("Pattern occurs at index %d\n", i-j);
        f++;
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
    return f;
}

char code[101000]="#include<bits/stdc++.h>using namespace std;int main(){    int i=2,j,k;    if(i<10)        printf(less than ten);    else    {        for(j=0;j<10;j++) {            if(i>10)                printf(not possible);  }    } return 0;}";

int main()
{
    int i,j,k;

    int if_c=0;
    int for_c=0;
    int while_c=0;

    if_c=KMP(code,"if");
    for_c=KMP(code,"for");
    while_c=KMP(code,"while");

    printf("Cyclomatiic complexity : %d\n",if_c + for_c + while_c + 1);

    return 0;
}
