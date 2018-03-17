#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int main()
{
    int i,j,k;
    int v;

    int mn=INT_MAX,mn_idx;

    scanf("%d",&v);

    for(i=1;i<=9;i++){
        scanf("%d",&arr[i]);

        if(mn>=arr[i])
        {
            mn=arr[i];
            mn_idx=i;
        }
    }

    int num=v/mn;
    int res=v%mn;

    for(i=0;i<num;i++)
    {
        for(j=9;j>=1;j--)
        {
            if(arr[j]<=mn+res)
            {
                res=res - (arr[j]-mn);
                break;
            }
        }
        printf("%d",j);
    }

    if(num==0)
        printf("-1\n");

    return 0;
}
