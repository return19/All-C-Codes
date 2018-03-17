#include<stdio.h>

typedef struct abc
{
    long long value;
    long long index;
}tip;
tip a[1000010],b[1000010];
long long memo[1000010];
void quicksort(tip x[],long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i].value<=x[pivot].value&&i<last)
                 i++;
             while(x[j].value>x[pivot].value)
                 j--;
             if(i<j){
                 temp=x[i].value;
                  x[i].value=x[j].value;
                  x[j].value=temp;
                  temp=x[i].index;
                  x[i].index=x[j].index;
                  x[j].index=temp;

             }
         }

         temp=x[pivot].value;
         x[pivot].value=x[j].value;
         x[j].value=temp;

         temp=x[pivot].index;
         x[pivot].index=x[j].index;
         x[j].index=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


int main()
{
    long long n,x,y,i,j,sum=0,last_a,last_b;
    scanf("%lld%lld%lld",&n,&x,&y);

    for(i=0;i<n;i++)
        {scanf("%lld",&a[i].value);   a[i].index=i;}

    for(i=0;i<n;i++)
        {scanf("%lld",&b[i]); b[i].index=i;}

    quicksort(a,0,n-1);
    quicksort(b,0,n-1);

    last_a=n-1;
    last_b=n-1;
    for(i=n;i>=1;i--)
    {

        while(memo[a[last_a].index]==1)
            last_a--;
            while(memo[b[last_b].index]==1)
            last_b--;

        if(a[last_a].value>=b[last_b].value)
        {
            x--;
            sum=sum+a[last_a].value;
            memo[a[last_a].index]=1;
            last_a--;
        }
        else
        {
            y--;
            sum=sum+b[last_b].value;
            memo[b[last_b].index]=1;
            last_b--;
        }
        if(x==0||y==0)
            break;
    }
    i--;
    while(x>0&&i>0)
    {
        x--;
        while(memo[a[last_a].index]==1)
            last_a--;

        sum=sum+a[last_a].value;
        i--;


    }
    while(y>0&&i>0)
    {
        y--;
        while(memo[b[last_b].index]==1)
            last_b--;
        sum=sum+b[last_b].value;
        i--;




    }

    printf("%lld\n",sum);

    return 0;

}

















