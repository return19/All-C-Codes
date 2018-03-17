#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,i,j,k;
    int n,n1;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&n1);

        int c=0;

        while(n!=(n&(-n)))
        {
            c++;
            n=n>>1;
        }
        if(n<n1){
            while(n!=n1)
            {
                c++;
                n=n<<1;
            }
        }
        else if(n>n1)
        {
            while(n!=n1)
            {
                c++;
                n=n>>1;
            }
        }

        printf("%d\n",c);
    }

    return 0;
}
