#include<stdio.h>

int main()
{
    int boys,girls,temp,div,rem;
    scanf("%d%d",&boys,&girls);

    while(boys!=-1&&girls!=-1)
    {
        if(boys<girls)
        {
           temp=boys;
           boys=girls;
           girls=temp;
        }
        if(boys==0)
        {
            printf("%d\n",girls);

        }
        else if(girls==0)
        {
            printf("%d\n",boys);

        }
        else if(boys==girls)
        {
            printf("1\n");

        }
        else if(girls==1)
        {
            if(boys%2==0)
            {
                printf("%d\n",boys/2);
            }
            else
                printf("%d\n",boys/2+1);

        }
        else
        {
            div=boys/(girls+1);
            rem=boys%(girls+1);
            if(rem==0)
            {
                printf("%d\n",div);

            }
            else
            {
                printf("%d\n",div+1);
            }
        }


        scanf("%d%d",&boys,&girls);
    }
    return 0;
}
