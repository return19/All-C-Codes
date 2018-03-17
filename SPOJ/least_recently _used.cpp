#include<bits/stdc++.h>
using namespace std;

int rs[10010];
int memo[10010];

int fr[10010];

int main()
{
    int n,f,i,j,k;
    int flag=0;
    int c1=0;
    int pos;
    int pf=0;

    memset(fr,-1,sizeof(fr));

    printf("Enter the number of pages in reference string : ");
    scanf("%d",&n);

    printf("\nEnter the reference string : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }

    printf("\nEnter the number of page frames : ");

    scanf("%d",&f);

    printf("\n***********************************************************\n");

    printf("\nRS\t   Page frames\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",rs[i]);
        flag=0;

        for(j=0;j<f;j++)
        {
            if(fr[j]==rs[i]||fr[j]==-1)
            {
                if(fr[j]==-1)
                    pf++;

                flag=1;
                pos=j;
                break;
            }
        }

        if(flag==1)
        {
            fr[j]=rs[i];

            for(j=0;j<f;j++)
            {
                printf("%d\t",fr[j]);
            }
            printf("\n");

            continue;
        }
        pf++;

        memset(memo,0,sizeof(memo));

        c1=0;

        for(j=0;j<f;j++)
        {
            for(k=i-1;k>=0;k--)
            {
                if(rs[k]==fr[j])
                {
                    memo[j]=k;
                    break;
                }
            }
        }

        int min1=memo[0];

        for(j=1;j<f;j++)
        {
            if(min1>memo[j])
            {
                c1=j;
                min1=memo[j];
            }
        }

        fr[c1]=rs[i];

        for(j=0;j<f;j++)
            {
                printf("%d\t",fr[j]);
            }
            printf("\n");

    }

     printf("\n***********************************************************\n");


    printf("\n\nNo. of page faults : %d\n",pf);
     printf("\n***********************************************************\n");


    return 0;
}








































/*#include<bits/stdc++.h>
using namespace std;

int rs[10010];
int memo[10010];

int fr[10010];

int main()
{
    int n,f,i,j,k;
    int flag=0;
    int c1=0;
    int pos;
    int pf=0;

    memset(fr,-1,sizeof(fr));

    printf("Enter the number of pages in reference string : ");
    scanf("%d",&n);

    printf("\nEnter the reference string : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }

    printf("\nEnter the number of page frames : ");

    scanf("%d",&f);

    printf("\n***********************************************************\n");

    printf("\nRS\t   Page frames\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",rs[i]);
        flag=0;

        for(j=0;j<f;j++)
        {
            if(fr[j]==rs[i]||fr[j]==-1)
            {
                if(fr[j]==-1)
                    pf++;

                flag=1;
                pos=j;
                break;
            }
        }

        if(flag==1)
        {
            fr[j]=rs[i];

            for(j=0;j<f;j++)
            {
                printf("%d\t",fr[j]);
            }
            printf("\n");

            continue;
        }
        pf++;

        memset(memo,0,sizeof(memo));

        c1=0;

        for(j=0;j<f;j++)
        {
            for(k=i-1;k>=0;k--)
            {
                if(rs[k]==fr[j])
                {
                    memo[j]=k;
                    break;
                }
            }
        }

        int min1=memo[0];

        for(j=1;j<f;j++)
        {
            if(min1>memo[j])
            {
                c1=j;
                min1=memo[j];
            }
        }

        fr[c1]=rs[i];

        for(j=0;j<f;j++)
            {
                printf("%d\t",fr[j]);
            }
            printf("\n");

    }

     printf("\n***********************************************************\n");


    printf("\n\nNo. of page faults : %d\n",pf);
     printf("\n***********************************************************\n");


    return 0;
}










*/









