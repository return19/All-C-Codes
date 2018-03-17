#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int main()
{
    int i,j,k;
    int n;

    int f1,f2;
    int c1=0,c2=0;
    int ans=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            if(c1==0){
                f1=i;
            }
            else{
                ans=1;
                break;
            }
            c1++;

            for(j=i;j<n-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    f2=j;
                }

            }
            if(j==n-1)
            {
                printf("yes\n");
                printf("%d %d\n",f1+1,f2+1);
                return 0;
            }

            if(arr[f2+1]<arr[f1-1]||arr[f1]>arr[f2+1])
            {
                printf("no\n");
                return 0;
            }

        }


    }

    if(ans==0)
    {
        printf("yes\n");

        printf("%d %d\n",f1+1,f2+1);
    }
    else
    {
        printf("no\n");
    }




    return 0;
}
