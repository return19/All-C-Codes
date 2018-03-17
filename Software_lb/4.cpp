#include<bits/stdc++.h>
using namespace std;

int test[50][3];

int s=0;
int e=100;


void gen_test()
{
    int mid=(s+e)/2;
    int i,j,k;
    int arr[]={s,s+1,e-1,e};

    for(i=0;i<13;i++)
        for(j=0;j<3;j++)
                test[i][j]=mid;
    j=-1;
    for(i=0;i<12;i++)
    {
        if(i%4==0)
            j++;
        test[i][j]=arr[i%4];
    }

  /*  for(i=0;i<13;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

int main()
{
    int i,j,k;
    scanf("%d%d",&s,&e);
    gen_test();

    printf("a\tb\tc\tD\tResult\n\n");
    for(i=0;i<13;i++)
    {
        int a,b,c;
        a=test[i][0];
        b=test[i][1];
        c=test[i][2];

        printf("%d\t%d\t%d\t%d\t",a,b,c,b*b-4*a*c);

        if(a==0)
        {
            printf("Not quadratic\n");
            continue;
        }

        if(b*b-4*a*c<0)
        {
            printf("Complex roots\n");
        }
        else if(b*b-4*a*c==0)
            printf("Equal roots\n");
        else
            printf("Real roots\n");
    }

    return 0;
}








