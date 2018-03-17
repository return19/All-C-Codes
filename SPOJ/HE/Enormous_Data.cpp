#include<stdio.h>

int main()
{
    int n,k,t,count1=0,i;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t%k==0)
            count1++;
    }
    printf("%d\n",count1);

    return 0;
}
