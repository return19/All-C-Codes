#include<bits/stdc++.h>
using namespace std;

int arr[1100];

int main()
{
    int test,i,j,t;

    int n,k;

    int pro=1;

    int ans=0;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&k);

        for(i=0;i<n;i++){
            scanf("%1d",&arr[i]);
        }

        pro=1;
        int c=0;

        for(i=0;i<k;i++)
        {

            if(arr[i]==0)
                c++;
            else
                pro *= arr[i];
        }
        ans=0;

        if(c>0)
            ans=0;
        else
            ans=pro;



        for(i=k;i<n;i++)
        {
            if(arr[i]==0)
            {
                c++;
                if(arr[i-k]==0)
                {
                    c--;
                }
                else
                    pro /= arr[i-k];

                continue;
            }
            else
            {
                if(arr[i-k]==0)
                {
                    c--;
                    pro *= arr[i];
                    if(c==0)
                    {
                        ans=max(ans,pro);
                    }
                }
                else
                {
                    pro /= arr[i-k];
                    pro *= arr[i];

                    if(c==0)
                        ans=max(ans,pro);

                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}









