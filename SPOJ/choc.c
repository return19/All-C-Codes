#include<stdio.h>

void main()
{
    int t,n[1000],m[1000],i,c1=0,r1=0;
    scanf("%d",&t);

    for(i=0;i<t;i++)
        scanf("%d%d",&n[i],&m[i]);

    for(i=0;i<t;i++)
    { c1=n[i];
      r1=c1;
        while(r1/m[i]!=0)
        {
            c1+=r1/m[i];
            r1/=m[i];
        }
        printf("\%d\n",c1);
    }

}
