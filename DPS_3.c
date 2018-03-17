#include<stdio.h>

int arr[1000010];


int main()
{
    int n,i,j,k,a,b,q,flag=0;;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);
        a--;
        b--;
        flag=0;
        for(j=a+1;j<b;j++)
        {
            if(arr[j]>arr[a])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
