#include<stdio.h>

int a[210][210];
int b[210][210];
inline int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int test,i,j,k,g,row,col;

    scanf("%d",&test);

    for(k=0;k<test;k++)
    {
        g=0;
        scanf("%d%d",&row,&col);

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(i=row-1;i>=0;i--)
        {
            for(j=col-1;j>=0;j--)
            {
                if(i==row-1)
                {
                    b[i][j]=a[i][j];
                }
                else
                {
                   if(j>=1&&j<=col-2)
                   {
                       b[i][j]=a[i][j]+max(max(b[i+1][j-1],b[i+1][j]),b[i+1][j+1]);

                   }
                   else if(j==0)
                   {
                       b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
                   }
                   else
                   {
                       b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j-1]);
                   }
                   if(g<b[i][j])
                       {
                           g=b[i][j];
                       }
                }
            }
        }
        printf("%d\n",g);
    }
    return 0;
}







