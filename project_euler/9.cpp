#include<bits/stdc++.h>
using namespace std;

int arr[3300];

int main()
{
    int test,i,j,k,t;

    int n;
    int ans=0;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        ans=0;

        for(i=1,j=n-1;i<j;)
        {
            k=n-i-j;

            if(k<j)
            {
                j--;
                continue;
            }

            if(i*i + j*j == k*k)
            {
                if(ans<i*j*k)
                    ans=i*j*k;
                i++;
                j--;
            }
            else if(i*i + j*j < k*k)
            {
                i++;
            }
            else
                j--;
        }

        if(ans==0)
            printf("-1\n");
        else
            printf("%d\n",ans);

       /* for(i=1;i<=n;i++)
        {
             if(n - i - (i+1) < (i+1 ))
                break;

            for(j=i+1;j+i<=n;j++)
            {
                k=n-i-j;

                if(k<j)
                    break;

                if((i*i + j*j == k*k))
                {
                    if(ans< i*j*k)
                    {
                        ans=i*j*k;
                    }
                }
            }

        }

        if(ans==0)
            printf("-1\n");
        else
            printf("%d\n",ans);*/

    }

    return 0;
}










