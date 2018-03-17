#include<stdio.h>

int main()

{

    int n,burst_tm[20],wait[20],turnaround[20],avwt=0,avtat=0,i,j;

    printf("Enter number of processes:");

    scanf("%d",&n);

    printf("\nEnter Burst Times\n");

    for(i=0;i<n;i++)

        {

            printf("Process %d:",i+1);

            scanf("%d",&burst_tm[i]);

        }

    wait[0]=0;

    for(i=1;i<n;i++)

        {

            wait[i]=0;

            for(j=0;j<i;j++)

                wait[i]+=burst_tm[j];

        }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)

        {

            turnaround[i]=burst_tm[i]+wait[i];

            avwt+=wait[i];

            avtat+=turnaround[i];

            printf("\nP %d\t\t%d\t\t%d\t\t%d",i+1,burst_tm[i],wait[i],turnaround[i]);

        }

    avwt/=i;

    avtat/=i;

    printf("\n\nAverage Waiting Time:%d",avwt);

    printf("\nAverage Turnaround Time:%d",avtat);

    return 0;

}
