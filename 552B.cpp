#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k;

    scanf("%d",&n);

    int ans=0;

    int temp=n;

    j=1;

    for(i=9;i<n;i=i*10+9)
    {
        ans += j* (9*pow(10,j-1));
        j++;
    }

    i= (i-9)/(pow(10,j));

    ans += n-i;

    printf("%d\n",ans);

    return 0;
}
