#include<bits/stdc++.h>
using namespace std;

char str[101000];

int arr[101000];

int main()
{
    int q;
    int i,j,k;

    int n;

    scanf("%s",str);

    n=strlen(str);

    if(str[0]==str[1])
        arr[0]=1;

    for(i=1;i<n-1;i++)
    {
        if(str[i]==str[i+1])
        {
            arr[i]=1 + arr[i-1];
        }
        else
            arr[i]=arr[i-1];
    }

    int x,y;

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);

        x--;
        y--;

        if(x==y)
        {
            printf("0\n");
        }
        else if(x==0)
        {
            printf("%d\n",arr[y-1]);
        }
        else
            printf("%d\n",arr[y-1]-arr[x-1]);
    }

    return 0;
}
