#include<stdio.h>

int main()
{
    int a[100][1000],terms[100],final[100],t,n[100][1000];
    int i,j,k,g,f1=0;

    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d",&terms[i]);
        for(j=0;j<terms[i];j++)
            scanf("%d",&a[i][j]);
    }

    for(i=0;i<t;i++)
    { f1=0;
        for(j=0;j<terms[i];j++)
        { if(a[i][j]!=n[i][j])
          {for(k=terms[i];k>j;k--)
            {
                if(a[i][k]==a[i][j])
                {
                    final[f1++]=k-j;
                    n[i][k]=a[i][k];
                }
            }
          }
        }
        if(f1==0)
        {
            final[0]=0;
        }
        g=final[0];
        for(j=0;j<f1;j++)
         if(g<final[j])
            g=final[j];

         printf("%d\n",g+1);
    }
    return 0;
}
