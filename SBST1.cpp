#include<bits/stdc++.h>
using namespace std;


char str[51000];

int s[51000];

long long n;

int cmp(const void *a,const void *b)
{
    return (strcmp((str+*((int*)a)),(str+*((int*)b))));
}


void suffix_arr()
{
    int i,j;

    for(i=0;i<n;i++)
        s[i]=i;

    qsort(s,n,sizeof(int),cmp);

}

long long lcp()
{
    long long count1=0;
    int i,j,k;
    char *str1,*str2;

    for(i=1;i<n;i++)
    {
        str1=str+s[i-1];
        str2=str+s[i];

        j=0;

        while(str1[j]==str2[j])
        {
            count1++;
            j++;
        }
    }

    return count1;
}


int main()
{
    long long test,i,j,k;
    long long count1,ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        scanf("%s",str);

        n=strlen(str);

        suffix_arr();

        count1=lcp();
        ans=(n*(n+1))/2-count1;
        printf("%lld\n",ans);

    }

    return 0;
}














