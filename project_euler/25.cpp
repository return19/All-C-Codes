#include<bits/stdc++.h>
using namespace std;

int ans[5100];
int main()
{
    int i,j,k;
    double phi = (1+sqrt(5))/2;
    ans[1]=1;
    for(i=2;i<=25000;i++){
        int temp = (double)i*(log10(phi)) - log10(5.0)/2.0 + 1;
       // cout<<i<<" "<<floor(dig[i])<<endl;
        if(!ans[temp])
            ans[temp] = i;
    }

    int test,t;
    int n;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
