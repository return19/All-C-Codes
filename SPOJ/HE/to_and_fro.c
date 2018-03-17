#include<stdio.h>
#include<string.h>
int main()
{
    char m[210];
    int i,j,k,cols,n;

    scanf("%d",&cols);

    while(cols!=0)
    {
        scanf("%s",m);
        n=strlen(m);

        for(i=0;i<cols;i++)
        {
            k=1;
            for(j=i;j<n;k++)
            {
                printf("%c",m[j]);
                if(k%2!=0)
                {
                    j=j+2*cols-1-2*i;
                }
                else
                {
                    j=j+1+2*i;
                }
            }
        }
        printf("\n");

        scanf("%d",&cols);
    }
    return 0;
}
