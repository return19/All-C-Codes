#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    int temp=0;
    while(n!=0)
    {
        temp=temp*10 +n%10;
        n/=10;
    }
    n=temp;

    int ans=0;

    while(n!=0)
    {
        if(n%10==4)
        {
            ans=ans*2 + 1;
        }
        else
            ans=ans*2 + 2;

        n/=10;
    }

    printf("%d\n",ans);


    return 0;
}
