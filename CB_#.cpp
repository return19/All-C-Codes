#include<bits/stdc++.h>
using namespace std;

int sv[50010];
int prime[50010],P=-1;

void sieve()
{
    int i,j,k;
    for(i=2;i<1010;i++)
    {
        if(sv[i]==0){
            prime[++P]=i;
            k=2;
            for(j=i*k;j<1010;j=i*k)
            {
                sv[j]=1;
                k++;
            }
        }
    }

}

int main()
{
    int test,i,j,k,x,y,n;
    scanf("%d",&test);
    sieve();

    /*for(i=0;i<100;i++)
        cout<<prime[i]<<" ";
    cout<<endl;*/
   // printf("%d %d\n",P,prime[100]);
    int count1=0,sq,temp,ca=0;;
    for(i=0;i<test;i++)
    {
        ca=0;
        scanf("%d%d%d",&x,&y,&n);

        for(j=x;j<=y;j++)
        {
            temp=j;

            count1=0;
            //sq=sqrt(temp);

            for(k=0;prime[k]<=temp/2;k++)
            {
                if(temp%prime[k]==0)
                {
                    //cout<<temp<<" "<<prime[k]<<"\n";
                    count1++;
                    /*while(temp%prime[k]==0)
                        temp=temp/prime[k];*/
                }
            }
            if(count1==0)
                count1++;
            if(count1==n)
                ca++;
        }

        printf("%d\n",ca);
    }


    return 0;
}
