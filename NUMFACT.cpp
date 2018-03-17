#include<bits/stdc++.h>
using namespace std;
long long arr[1000010],m;
long long val[10010];

void calc(long long p)
{
    long long i,j,k,x=0,p1=p;
    long long temp=p,flag=0;


    if(p%2==0)
    {
        flag=1;
        x=0;
        while(p%2==0&&p!=0)
        {
            x++;
            p=p/2;
        }
        arr[2]+=x;

    }


        for(i=3;i<=p1/2;i++)
        {
            temp=p;
            x=0;
            while(temp%i==0)
            {
                flag=1;
                temp=temp/i;

                x++;
            }
            arr[i]+=x;
        }
        if(flag==0)
            arr[p1]++;
}

int main()
{
    long long test,i,j,k,n,sum;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=1;
        memset(arr,0,sizeof(arr));
        scanf("%lld",&n);
        m=0;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&val[j]);
            if(m<val[j])
                m=val[j];
        }



        for(j=0;j<n;j++)
        {
            //cout<<"run "<<j+1<<endl;
            calc(val[j]);
        }

       /* for(j=0;j<=m;j++){
            cout<<j<<" "<<arr[j]<<endl;
        }*/

        for(j=0;j<=m;j++)
        {
            if(arr[j])
                sum=sum*(arr[j]+1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
