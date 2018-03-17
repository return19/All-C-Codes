#include<bits/stdc++.h>
using namespace std;

int arr[10002000];
unsigned long long dont[100200],DONT;
unsigned long long n,k;
unsigned long long check()
{
    arr[0]=1;
    unsigned long long i,j,k,last,first;
    for(i=1;i<=n;i++)
    {
        if(dont[DONT]==i)
        {
            DONT++;
            continue;
        }
        for(j=(i*(i+1))/2;j>=i;j--)
        {

            if(arr[j-i]==1)
            {
                arr[j]=1;
            }
            if(j==i)
            {
                if(arr[j-1]!=1)
                {
                    return j-1;
                }
            }
        }
    }
    for(i=1;i<=(n*(n+1))/2;i++)
    {
        if(arr[i]!=1)
        {
            return i;
        }
    }
}

int main()
{
    unsigned long long test,i,j,index;
    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        DONT=0;
        memset(arr,0,sizeof(arr));
        scanf("%llu%llu",&n,&k);
        for(j=0;j<k;j++)
        {
            scanf("%llu",&dont[j]);
        }

        index=check();
        //for(j=1;j<=(n*(n+1))/2;j++)
          //  cout<<arr[j]<<" ";
        if(index%2!=0)
        {
            printf("Chef\n");
        }
        else
        {
            printf("Mom\n");
        }
    }
    return 0;
}









