#include<stdio.h>

int main()
{
    int mix[105],i,mix1,g,smoke=0;

    while(scanf("%d",&mix1)!=EOF)
    {   smoke=0;
        for(i=0;i<mix1;i++)
        {
            scanf("%d",&mix[i]);
        }

        while(mix1!=1)
        {   g=0;
            for(i=1;i<mix1;i++)
            {
                if(((mix[g]+mix[g+1])%100)>((mix[i]+mix[i+1])%100))
                {
                    g=i;
                }
            }
            smoke+=mix[g]*mix[g+1];
            mix[g]=(mix[g]+mix[g+1])%100;
            mix1--;
            for(i=g+1;i<mix1;i++)
            {
                mix[i]=mix[i+1];
            }

        }
        printf("%d\n",smoke);


    }
    return 0;
}
