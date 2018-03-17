#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int x;

    scanf("%d",&x);

    int s=x/5;

    if(x%5!=0)
        s++;
    printf("%d\n",s);

    return 0;
}
