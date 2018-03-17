#include<bits/stdc++.h>
using namespace std;

char str[10100000];

int arr[10100000];
int temp[10100000];

int main()
{
    int i,j,k;
    int test,t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",str);
        n=strlen(str);

        if(n>5 || n<2)
        {
            printf("invalid group code\n");
            continue;
        }

        for(i=0;i<n;i++){
            arr[i]=str[i]-'0';
            temp[i]=arr[i];
        }

        next_permutation(arr,arr+n);
        int f=0;
        for(i=0;i<n;i++)
        {
            if(temp[i]>arr[i])
            {
                f=1;
                break;
            }
            else if(arr[i]>temp[i])
                break;
        }
        if(f==1)
        {
            for(i=0;i<n;i++)
                printf("%d",temp[i]);
            printf("\n");
            continue;
        }
        for(i=0;i<n;i++)
            printf("%d",arr[i]);
        printf("\n");
    }


    return 0;
}
