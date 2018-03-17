#include<bits/stdc++.h>
using namespace std;

char str[10100];

map<char,int> memo;

int main()
{
    int test,t,i,j,k;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();

        scanf("%s",str);


        n=strlen(str);

        for(i=0;i<n;i++)
            memo[str[i]]++;

        int ans=0;

        if(memo['L']>=2&&memo['T']>=2&&memo['I']>=2&&memo['M']>=2&&memo['E']>=2)
            ans=1;

        if(n==9&&memo['L']>=2&&memo['T']>=2&&memo['I']>=2&&memo['M']>=2&&memo['E']>=1)
            ans=1;

        if(ans==0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}

