#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[210100];
unsigned long long a[210100][2];
unsigned long long idx=-1;
int main()
{

    unsigned long long i,j,k;
    unsigned long long n,m;

    scanf("%llu%llu",&m,&n);

    for(i=0;i<n;i++)
    {
        scanf("%llu",&arr[i]);
    }

    for(i=1;i<n;i++)
    {
        unsigned long long c=0;

        for(j=0;j<n-i+1;j++)
        {

            k=j+i-1;
            unsigned long long pro=1;
            for(unsigned long long t=j;t<=k;t++)
            {
                pro=pro*arr[t];

                if(pro%m==0)
                {
                    a[++idx][0]=j+1;
                    a[idx][1]=k+1;
                    //cout<<j<<" "<<k<<endl;
                   c++;
                   break;
                }
            }
        }

        if(c>0)
        {
            printf("Minimum interval length: %llu\n",i);
            printf("Found intervals:\n");
            for(unsigned long long t=0;t<=idx;t++)
            {
                printf("[%llu, %llu]\n",a[t][0],a[t][1]);
            }

            return 0;
        }
    }

    printf("NONE\n");


    return 0;
}
