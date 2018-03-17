#include<bits/stdc++.h>
using namespace std;

long long start[10001000];
long long last[10001000];
long long c_val[10001000];
long long memo[10001000];


void sort1(long long first,long long last1){
    long long pivot,j,temp,i;

     if(first<last1){
         pivot=first;
         i=first;
         j=last1;

         while(i<j){
             while(c_val[i]<=c_val[pivot]&&i<last1)
                 i++;
             while(c_val[j]>c_val[pivot])
                 j--;
             if(i<j){
                 temp=c_val[i];
                  c_val[i]=c_val[j];
                  c_val[j]=temp;

                  temp=start[i];
                  start[i]=start[j];
                  start[j]=temp;

                  temp=last[i];
                  last[i]=last[j];
                  last[j]=temp;
             }
         }

         temp=c_val[pivot];
         c_val[pivot]=c_val[j];
         c_val[j]=temp;

         temp=start[pivot];
         start[pivot]=start[j];
         start[j]=temp;

         temp=last[pivot];
         last[pivot]=last[j];
         last[j]=temp;

         sort1(first,j-1);
         sort1(j+1,last1);

    }
}


int main()
{
    long long n,m,i,j,k;
    long long temp1,temp2,c;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&temp1,&temp2,&c);
        start[i]=temp1;
        last[i]=temp2;
        c_val[i]=c;
    }

    sort1(0,m);

    long long c2=0;

    for(i=0;i<m&&i<n/2;i++)
    {

        if(memo[start[i]]!=1)
        {
            memo[start[i]]=1;
            c2++;
        }

        if(c2==n/2)
            break;

        if(memo[last[i]]!=1)
        {
            memo[last[i]]=1;
            c2++;
        }

        if(c2==n/2)
            break;

    }
    long long count1=0;
    for(i=0;;i++)
    {
        if(count1==n/2)
            break;

        if(memo[i]==0)
        {
            printf("%lld ",i+1);
            count1++;
        }
    }


    return 0;

}
