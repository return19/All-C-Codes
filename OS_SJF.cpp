#include<stdio.h>

int main()

{

    int burst[20],p[20],wait[20],turnard[20],i,j,n,total=0,pos,temp;

    float avg_wt,avg_tat;

    printf("Enter number of process:");

    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");

    for(i=0;i<n;i++)

    {

        printf("p %d:",i+1);

        scanf("%d",&burst[i]);

        p[i]=i+1;

    }

    for(i=0;i<n;i++)

    {

        pos=i;

        for(j=i+1;j<n;j++)

        {

            if(burst[j]<burst[pos])

                pos=j;

        }

        temp=burst[i];

        burst[i]=burst[pos];

        burst[pos]=temp;

        temp=p[i];

        p[i]=p[pos];

        p[pos]=temp;

    }

    wait[0]=0;

    for(i=1;i<n;i++)

    {

        wait[i]=0;

        for(j=0;j<i;j++)

            wait[i]+=burst[j];

        total+=wait[i];

    }

    avg_wt=(float)total/n;

    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)

    {

        turnard[i]=burst[i]+wait[i];

        total+=turnard[i];

        printf("\nP %d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst[i],wait[i],turnard[i]);

    }

    avg_tat=(float)total/n;

    printf("\n\nAverage Waiting Time = %f",avg_wt);

    printf("\nAverage Turnaround Time = %f\n",avg_tat);

}
