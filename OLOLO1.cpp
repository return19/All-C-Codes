#include<bits/stdc++.h>
using namespace std;
long long arr[1000010];
int main()
{
    long long index,i,res;
    scanf("%lld",&index);
    for(i=0;i<index;i++)
    {
        scanf("%lld",&arr[i]);
    }
    res=arr[0];
    for(i=1;i<index;i++)
    {
        res=res^arr[i];
    }
    printf("%lld\n",res);
    return 0;
}
