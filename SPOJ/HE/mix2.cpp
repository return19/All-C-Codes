
#include<stdio.h>

int color[100][100];
long smoke[100][100];

int main()
{
    int n;

    while((scanf("%i",&n)!=EOF))
    {
        int i;
        for( i=0;i<n;i++)
        scanf("%i",&color[i][i]);

        for( i=1;i<n;i++)
        {
            int j;
            for(j=0;j<n-i;j++)
            {
                smoke[j][j+i]=100000000;

                int k;

                for( k=0;k<i;k++)
                {
                    long temp=smoke[j][j+k]+smoke[j+1+k][j+i]+color[j][j+k]*color[j+1+k][j+i];

                    if(temp<smoke[j][j+i])
                    {
                        smoke[j][j+i]=temp;
                        color[j][j+i]=(color[j][j+k]+color[j+1+k][j+i])%100;
                    }
                }
            }
        }

        printf("%ld\n",smoke[0][n-1]);
    }
}
