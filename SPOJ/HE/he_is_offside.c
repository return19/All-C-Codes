#include<stdio.h>
int atk[110];
int def[110];

int main()
{
    int a,d,i,fir,sec,s,p;
    scanf("%d%d",&a,&d);

    while(a!=0&&d!=0)
    {
        s=9999999;
        for(i=0;i<a;i++)
        {
            scanf("%d",&atk[i]);
            if(s>atk[i])
            {
                s=atk[i];
            }
        }
        fir=9999999;sec=9999999;
        for(i=0;i<d;i++)
         {
             scanf("%d",&def[i]);
             if(fir>def[i])
             {
                 fir=def[i];
                 p=i;
             }
         }
         def[p]=99999999;
         for(i=0;i<d;i++)
         {
             if(sec>def[i])
             {
                 sec=def[i];
             }

         }
        /* printf("\n%d %d\n",s,sec);*/
         if(s>=sec)
         {
             printf("N\n");
         }
         else
         {
             printf("Y\n");
         }
         scanf("%d%d",&a,&d);
    }
    return 0;
}
