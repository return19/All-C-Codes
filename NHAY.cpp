#include<bits/stdc++.h>
using namespace std;

long long m,n;

char pat[100000010],txt[100000010],lps[100000010];

void lps_compute()
{
    long long i,j,k,len=0;
    lps[len]=0;

    for(i=1;i<m;i++)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
                i--;
            }
            else
            {
                lps[i]=0;
            }
        }
    }

}

void kmp()
{
    long long i,j,k;
    lps_compute();
    for(i=0,j=0;i<n;)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            printf("%lld\n",i-j);
            j=lps[j-1];
        }
        else if(i<n&&pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
    }

}

int main()
{
    long long i,j,k;

    //scanf("%d",&test);

    while(scanf("%lld",&m)>0)
    {

        scanf("%s",pat);
        scanf("%s",txt);
        n=strlen(txt);

        kmp();
        printf("\n");
    }

    return 0;
}
