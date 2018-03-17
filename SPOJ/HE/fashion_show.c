#include<stdio.h>

int men[10010];
int women[10010];

void qsort(int a[],int lb,int ub)
{
    int i;
    if(lb<ub)
    {
        i=part(a,lb,ub);
        qsort(a,lb,i-1);
        qsort(a,i+1,ub);
    }
}

int part(int a[],int lb,int ub)
{
    int i=lb,temp,pivot=lb,j=ub;
    if(i<j)
    {while(i<j)
    {
        while(a[i]<=a[pivot]&&i<=ub)
            i++;

        while(a[j]>a[pivot]&&j>=0)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    return j;
    }
}

int main()
{
    int test,i,j,index,sum=0;

    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%d",&index);
        for(j=0;j<index;j++)
        {
            scanf("%d",&men[j]);
        }
        for(j=0;j<index;j++)
        {
            scanf("%d",&women[j]);
        }
        qsort(men,0,index-1);
        /*for(j=0;j<index;j++)
            printf("%d ",men[j]);*/
        qsort(women,0,index-1);

        for(j=0;j<index;j++)
        {
            sum=sum+men[j]*women[j];
        }
        printf("%d\n",sum);
    }
    return 0;
}







