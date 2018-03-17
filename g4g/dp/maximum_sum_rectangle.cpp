#include<bits/stdc++.h>
using namespace std;

int arr[1100][1100];
int temp[1100];

int n,m;

int s1,s2,e1,e2;

int kadane(int a[],int &s1,int &e1)
{
    int i,j,k;
    int cur=0,t_s=0;
    int max_sum=INT_MIN;


    for(i=0;i<n;i++)
    {
        cur+=a[i];

        if(cur<0)
        {
            cur=0;
            t_s=i+1;

        }

        if(cur>max_sum)
        {
            max_sum=cur;
            s1=t_s;
            e1=i;
        }
    }

    return max_sum;
}

int kadane2d(int arr[][1100])
{
    int i,j,k;


    int max_sum=INT_MIN;
    int t_s1=0,t_e1=0;
    for(i=0;i<m;i++)
    {
        memset(temp,0,sizeof(temp));

        for(j=i;j<m;j++)
        {
            for(k=0;k<n;k++)
                temp[k]+=arr[k][j];

                int temp1=kadane(temp,t_s1,t_e1);

                if(temp1>max_sum)
                {

                    //cout<<"here"<<endl;
                    s1=t_s1;
                    e1=t_e1;
                    s2=i;
                    e2=j;

                    max_sum=temp1;
                }

        }
    }

    return max_sum;
}

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }



    printf("%d\n",kadane2d(arr));
 printf("%d %d %d %d\n",s1,s2,e1,e2);

}
