#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,i,j,k;
    int temp;
    scanf("%d",&n);


    if(n==1)
    {
        printf("1\n1\n");
        return 0;
    }
    else if(n==2)
    {
        printf("1\n1\n");
        return 0;
    }
    else if(n==3)
    {
        printf("2\n1 3\n");
        return 0;
    }
    else if(n==4)
    {
        printf("4\n3 1 4 2\n");
        return 0;
    }
    else
    {
        printf("%d\n",n);
    }
    printf("1");
    for(i=3;i<=n;i=i+2)
    {
        printf(" %d",i);
    }
    printf(" 2");
    for(i=4;i<=n;i=i+2)
    {
        printf(" %d",i);
    }
    printf("\n");



    return 0;
}
