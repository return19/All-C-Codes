#include<bits/stdc++.h>
using namespace std;

char str[1000100];

long long n_of_1[1000100];

int main()
{
    long long test,n,k,q,l,r;
    long long i,j,x,y;
    long long sum=0;
    long long last;
    long long flag;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        memset(n_of_1,0,sizeof(n_of_1));
        scanf("%lld%lld%lld",&n,&k,&q);

        scanf("%s",str);

        if(str[0]=='1')
        {
            n_of_1[1]=1;
        }

        for(j=2;j<=n;j++)
        {
            if(str[j-1]=='1')
            {
                n_of_1[j]=n_of_1[j-1]+1;
            }
            else
            {
                n_of_1[j]=n_of_1[j-1];
            }
        }

        /*for(j=0;j<=n;j++)
            cout<<n_of_1[j]<<" ";
        cout<<endl;*/

        for(j=0;j<q;j++)
        {
            sum=0;  flag=0;
            scanf("%lld%lld",&l,&r);

            l--;
            r--;

            y=k-1;

            last=l-1;

            if(k>=r-l+1)
            {
                printf("%lld\n",((r-l+1)*(r-l+1)+(r-l+1))/2);
                continue;
            }

            for(x=l;x<=r;x++)
            {

                for(y=y+1;;y++)
                {
                    if(n_of_1[y+1]-n_of_1[x]>k||((y+1-(x+1)+1)-(n_of_1[y+1]-n_of_1[x])>k)||y>r)
                    {
                        sum=sum+(((y-1)-x+1)*((y-1)-x+1)+((y-1)-x+1))/2-(((last)-x+1)*((last)-x+1)+((last)-x+1))/2;
                        //cout<<y-1<<" "<<x<<endl;
                        //cout<<"sum "<<sum<<endl;

                        if(y>r)
                        {
                            flag==1;
                        }
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
                y--;
                last=y;
            }


            printf("%lld\n",sum);

        }

    }


    return 0;
}
