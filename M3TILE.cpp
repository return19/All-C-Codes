#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    int t[31];
    t[0]=1;
    t[1]=0;
    t[2]=3;
    t[3]=0;
    for(i=4;i<=31;i++)
    {
        t[i]=4*t[i-2]-t[i-4];
    }
    scanf("%d",&n);
    while(n!=-1)
    {
        printf("%d\n",t[n]);
        scanf("%d",&n);
    }
    return 0;
}
