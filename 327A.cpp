#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int main()
{
    int n;
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int c;
    int ans=0;

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            c=0;

            for(k=0;k<n;k++)
            {
                if(k<i||k>j)
                {
                    if(arr[k]==1)
                        c++;
                }
                else
                {
                    if(arr[k]==0)
                        c++;
                }
            }

            ans=max(ans,c);
        }
    }

    printf("%d\n",ans);

    return 0;
}
