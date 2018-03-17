#include<bits/stdc++.h>
using namespace std;

long long arr[1100];
long long a[1100];
long long pos[1100];

long long graph[2100][2100];

long long visited[1100];



void quicksort(long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i]>=arr[pivot]&&i<last)
                 i++;
             while(arr[j]<arr[pivot])
                 j--;
             if(i<j){
                 temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;

                  temp=pos[i];
                  pos[i]=pos[j];
                  pos[j]=temp;


             }
         }

         temp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=temp;

         temp=pos[pivot];
         pos[pivot]=pos[j];
         pos[j]=temp;

         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}


int main()
{
    long long i,j,k;
    long long n,m;
    long long t1,t2;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        a[i]=arr[i];
        pos[i]=i;
    }

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&t1,&t2);

        t1--;
        t2--;

        graph[t1][t2]=1;
        graph[t2][t1]=1;
    }

    quicksort(0,n-1);



   /* for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for(i=0;i<n;i++)
        cout<<pos[i]<<" ";
    cout<<endl;*/

    long long sum=0;

    for(i=0;i<n;i++)
    {
        visited[pos[i]]=1;

        for(j=0;j<n;j++)
        {
            if(!visited[j]&&graph[pos[i]][j]==1)
            {
                //cout<<i<<" "<<j<<endl;

                sum=sum+a[j];
            }
        }
    }

    printf("%lld\n",sum);



    return 0;
}















