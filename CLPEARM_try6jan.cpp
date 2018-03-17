#include<bits/stdc++.h>
using namespace std;

long long arr[100200];

void quicksort(long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i]<=arr[pivot]&&i<last)
                 i++;
             while(arr[j]>arr[pivot])
                 j--;
             if(i<j){
                 temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
             }
         }

         temp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=temp;

         quicksort(first,j-1);
         quicksort(j+1,last);
    }
}


int main()
{
    long long test,n,k,start,last,sum,i,j;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&k);
        if(k==0)
        {
            if(((n*(n+1))/2)%2==0)
            {
                printf("Chef\n");
            }
            else
            {
                printf("Mom\n");
            }
            continue;
        }
        arr[0]=0;
        for(j=1;j<=k;j++)
        {
            scanf("%lld",&arr[j]);
        }
        arr[j]=n+1;

        quicksort(1,k);
       // for(j=0;j<k+2;j++)
         //   cout<<arr[j]<<" ";
        //cout<<endl;
        //start=0;
        sum=0;
        for(j=1;j<k+2;j++)
        {
            start=arr[j-1];   last=arr[j]-1;
            if(sum<start)
                break;
            sum=sum+(last*(last+1))/2-(start*(start+1))/2;
        }
        //cout<<sum<<endl;
        if(sum%2==0)
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
















