#include<bits/stdc++.h>
using namespace std;

int first,last,mid;
int test[1000][25];

int val[10];

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    scanf("%d%d",&first,&last);

    for(i=0;i<n;i++)
        printf("%c\t",65+i);
    printf("\n\n");

    val[0]=first-1;
    val[1]=first;
    val[2]=first+1;

    val[3]=last-1;
    val[4]=last;
    val[5]=last+1;

    mid=(first+last)/2;

    for(i=0;i<6*n+1;i++)
    {
        for(j=0;j<n;j++)
        {
            test[i][j]=mid;
        }
    }

    j=-1;

    for(i=0;i<6*n;i++)
    {
        if(i%6==0)
            j++;
        test[i][j]=val[i%6];
    }

    for(i=0;i<6*n+1;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",test[i][j]);
        printf("\n");
    }


    return 0;
}
