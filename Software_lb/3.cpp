#include<bits/stdc++.h>
using namespace std;

char txt[101000],pat[101000];
int n1,n2;

void match(char *txt,char *pat)
{
    int i,j,k;
    int n1=strlen(txt);
    int n2=strlen(pat);
    int f=0;
    for(i=0;i<n1-n2+1;i++)
    {
        if(txt[i]==pat[0])
        {
            for(j=0;j<n2;j++)
            {
                if(txt[i+j]!=pat[j])
                    break;
            }
            if(j==n2){
                printf("Pattern occurs at index %d\n",i);
                f=1;
            }
        }
    }
    if(f==0)
        printf("Pattern doesn't occur\n");
}

int main()
{
    int i,j,k;
    scanf("%s",txt);
    scanf("%s",pat);

    match(txt,pat);

    return 0;
}







