#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);

    while(n!=0)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        int ans=0;

        for(i=1;i<=n;i++)
        {
            if(i==arr[i])
                continue;
            else
            {
                if(arr[arr[i]]==i)
                    continue;
                else{
                    ans=1;
                    break;
                }
            }
        }

        if(ans==0)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");

        scanf("%d",&n);
    }

    return 0;
}












