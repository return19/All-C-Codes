#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int a,b,c;
    int x,y,z;
    int xtra=0;

    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&x,&y,&z);

    xtra=max(0,a-x)/2 +max(0,b-y)/2 +max(0,c-z)/2;

    int req=0;

    if(x>a)
        req+=x-a;
    if(y>b)
        req+=y-b;
    if(z>c)
        req+=z-c;

    if(req<=xtra)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
