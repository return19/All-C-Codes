#include<stdio.h>
#include<string.h>

int main()

{

    char p[100][5];

    int et[1000],wt[1000],timer=3,count,pt[1000],rt,i,j,totwt=0,t,n=5,found=0,m;

    float avgwt;

    for(i=0;i<n;i++)

    {

        printf("Enter Process name : ");

        scanf("%s",&p[i]);

        printf("Enter the Processing/Burst time : ");

        scanf("%d",&pt[i]);

    }

    m=n;

    wt[0]=0;

    i=0;

    do

    {

        if(pt[i]>timer)

        {

            rt=pt[i]-timer;

            strcpy(p[n],p[i]);

            pt[n]=rt;

            et[i]=timer;

            n++;

        }

        else

        {

            et[i]=pt[i];

        }

        i++;

        wt[i]=wt[i-1]+et[i-1];

    }while(i<n);

    count=0;

    for(i=0;i<m;i++)

    {

        for(j=i+1;j<=n;j++)

        {

            if(strcmp(p[i],p[j])==0)

            {

                count++;

                found=j;

            }

        }

    }

    for(i=0;i<n;i++)

    {

        totwt+=wt[i];

    }

    avgwt=(float)totwt/m;

    for(i=0;i<n;i++)

    {

        printf("\n%s\t%d\t%d",p[i],pt[i],wt[i]);

    }

    printf("\nTotal Waiting time %d\n",totwt);

    printf("Total avgtime %f",avgwt);

}
