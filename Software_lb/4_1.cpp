#include<bits/stdc++.h>
using namespace std;


int test[500][3];

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
    int n;

    scanf("%d",&n);

    printf("%d\n",6*n+1);
}
