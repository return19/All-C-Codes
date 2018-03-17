#include<stdio.h>
int a[1500][1500];
int b[1500][1500];
inline int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int test,i,j,k,g,row;

    scanf("%d",&test);

    for(k=0;k<test;k++)
    {
        scanf("%d",&row);

        for(i=0;i<row;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        g=0;
        for(i=row-1;i>=0;i--)
        {
            for(j=i;j>=0;j--)
            {
                if(i==row-1)
                {
                    b[i][j]=a[i][j];
                }
                else
                {
                    b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
                    if(g<b[i][j])
                    {
                        g=b[i][j];
                    }
                }
            }

        }printf("%d\n",g);
    }
    return 0;
}









