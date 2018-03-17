#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[1010][1010];

int temp[1010];
int s1,s2,e1,e2;

int kadane(int a[],int &s,int &e)
{
    int i,j,k;

    int t_s=0;
    int max1=INT_MIN;

    int cur=0;

    s=-1;
    e=-1;


    for(i=0;i<m;i++)
    {
        cur+=a[i];

        if(cur<0)
        {
            t_s=i+1;
            cur=0;
        }
        else if(cur>max1)
        {
            max1=cur;
            s=t_s;
            e=i;
        }
    }

    return max1;
}

int find_ans()
{
    int i,j,k;

    int t;


    int max1=INT_MIN;
    int s_t,e_t;

    s1=-1;
    s2=-1;
    e1=-1;
    e2=-1;

    for(i=0;i<n;i++)
    {
        memset(temp,0,sizeof(temp));

        for(j=i;j<n;j++)
        {
            for(k=0;k<m;k++)
                temp[k]+=arr[k][j];

            t=kadane(temp,s_t,e_t);

            if(t>max1)
            {
                //cout<<t<<" ";
                s1=s_t;
                e1=e_t;
                s2=i;
                e2=j;
                max1=t;
               // cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<" "<<max1<<endl;


            }
        }
    }

    return max1;
}

int main()
{
    int i,j,k;

    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int ans=find_ans();

    printf("\n%d %d %d %d\n",s1,s2,e1,e2);

    printf("%d",ans);

    return 0;
}
