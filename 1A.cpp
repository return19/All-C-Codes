#include<bits/stdc++.h>
using namespace std;

long long arr[1010][1010];

int main()
{
    long long test,i,j,k;

    long long n,m;
    long long temp;

    scanf("%lld%lld",&n,&m);


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%lld",&arr[i][j]);
        }
    }


    long long flag=0;


    if(n%2==0)
    {
        flag=0;

        while(flag!=1)
        {


            for(i=0,j=n-1;i<j;i++,j--)
            {
                for(k=0;k<m;k++)
                {
                    //cout<<"i :"<<i<<" j:"<<j<<" k:"<<k<<endl;

                    if(arr[i][k]!=arr[j][k])
                    {
                        flag=1;

                        break;
                    }
                }

            }

            if(n==1)
                break;

            //cout<<"here"<<endl;
            if(flag==0)
                n=n/2;

            if(n%2!=0)
            {
                break;
            }




        }

        printf("%lld\n",n);
    }
    else
    {
        printf("%lld\n",n);
    }

    return 0;
}











