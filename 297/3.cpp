#include<bits/stdc++.h>
using namespace std;

char str[501000];
int cnt[501000];
int main()
{
    int i,j,k;
    scanf("%s",str);
    int n=strlen(str);
    int m,x;
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        x--;
        cnt[x]++;
    }

    for(i=1;i<n;i++)
        cnt[i]+=cnt[i-1];

    for(i=0;i<n/2;i++)
    {
        if(cnt[i]%2!=0)
            swap(str[i],str[n-i-1]);
    }

    printf("%s",str);


    return 0;
}

