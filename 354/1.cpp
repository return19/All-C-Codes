#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n;
    int x,y,z;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);

        if(x==1)
            y=i;
        if(x==n)
            z=i;
    }

    printf("%d\n",max(max(y,n-y-1),max(z,n-z-1)));
    return 0;
}
