#include<bits/stdc++.h>
using namespace std;

int arr[1010000];

int d[3];

int main()
{
    int i,j;
    int n;
    int k,l;

    scanf("%d%d%d",&k,&l,&n);
    d[0]=1;
    d[1]=k;
    d[2]=l;
    arr[0]=0;

    for(i=0;i<=1000100;i++)
    {
        if(arr[i]==0)
            for(j=0;j<3;j++)
                arr[i+d[j]]=1;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        if(arr[k])
            printf("A");
        else
            printf("B");
    }

    return 0;
}
