#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
long long n,m,k;


long long s_layer[100010],e_layer[100010];
long long s_vertex[100010],e_vertex[100010];


pair<long long,long long> p1,p2;
pair< pair<long long,long long>,pair<long long,long long> > p;

map< pair< pair<long long,long long>,pair<long long,long long> >,long long > val_s;

map<long long,long long> memo;


long long power(long long x, long long y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2)%M;
    if (y%2 == 0)
        return (temp*temp)%M;
    else
        return (((x*temp)%M)*temp)%M;
}




/*long long power(long long x,long long y)
{
    long long i,j,k=1;

    if(y==0)
        return 1;

    for(i=1;i<=y;i++)
    {
        k=(k*x)%M;
    }

    return k;
}*/

/////////////// quick sort

void quicksort(long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(s_layer[i]<=s_layer[pivot]&&i<last)
                 i++;
             while(s_layer[j]>s_layer[pivot])
                 j--;
             if(i<j){
                 temp=s_layer[i];
                  s_layer[i]=s_layer[j];
                  s_layer[j]=temp;

                  temp=s_vertex[i];
                  s_vertex[i]=s_vertex[j];
                  s_vertex[j]=temp;

                  temp=e_layer[i];
                  e_layer[i]=e_layer[j];
                  e_layer[j]=temp;

                  temp=e_vertex[i];
                  e_vertex[i]=e_vertex[j];
                  e_vertex[j]=temp;
             }
         }

         temp=s_layer[pivot];
         s_layer[pivot]=s_layer[j];
         s_layer[j]=temp;

         temp=s_vertex[pivot];
          s_vertex[pivot]=s_vertex[j];
          s_vertex[j]=temp;

          temp=e_layer[pivot];
          e_layer[pivot]=e_layer[j];
          e_layer[j]=temp;

          temp=e_vertex[pivot];
          e_vertex[pivot]=e_vertex[j];
          e_vertex[j]=temp;

         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}



///////////




int main()
{
    long long i,j,count1=0,ans=0;

    scanf("%lld%lld%lld",&n,&m,&k);

    for(i=0;i<k;i++)
    {
        scanf("%lld%lld%lld%lld",&s_layer[i],&s_vertex[i],&e_layer[i],&e_vertex[i]);
        memo[s_layer[i]]=1;
    }

    quicksort(0,k-1);
    ///// to be sorted


    for(i=k-1;i>=0;i--)
    {
        count1=0;

        for(j=i+1;j<k;j++)
        {
            if(e_layer[i]==s_layer[j]&&e_vertex[i]==s_vertex[j])
            {
                p1.first=s_layer[j];
                p1.second=s_vertex[j];
                p2.first=e_layer[j];
                p2.second=e_vertex[j];
                p.first=p1;
                p.second=p2;

                count1=(count1+val_s[p])%M;
            }
            else if(e_layer[i]<s_layer[j])
            {
                p1.first=s_layer[j];
                p1.second=s_vertex[j];
                p2.first=e_layer[j];
                p2.second=e_vertex[j];
                p.first=p1;
                p.second=p2;

               // count1=(count1+(power(m,j-i-1)*(val_s[p]))%M)%M;
                count1=(count1+(power(m,s_layer[j]-e_layer[i]-1)*(val_s[p]))%M)%M;
            }
        }

        p1.first=s_layer[i];
        p1.second=s_vertex[i];
        p2.first=e_layer[i];
        p2.second=e_vertex[i];
        p.first=p1;
        p.second=p2;

        val_s[p]=count1;

        if(e_layer[i]!=n+1)
        {
            val_s[p]=(val_s[p]+power(m,n-e_layer[i]))%M;
        }
        else
        {
            val_s[p]=(val_s[p]+1)%M;    ////actually val_s[p]=1;
        }
    }

    ans=0;
    j=0;

    long long prev_val=1,lim=0,pow_r;

    for(j=0;j<k;j++)
    {
        if(s_layer[j]==0)
                {
                    p1.first=s_layer[j];
                    p1.second=s_vertex[j];
                    p2.first=e_layer[j];
                    p2.second=e_vertex[j];
                    p.first=p1;
                    p.second=p2;
                    ans=(ans+val_s[p])%M;
                }
                else
                {
                    p1.first=s_layer[j];
                    p1.second=s_vertex[j];
                    p2.first=e_layer[j];
                    p2.second=e_vertex[j];
                    p.first=p1;
                    p.second=p2;

                    pow_r=(power(m,s_layer[j]-lim-1))%M;

                    pow_r=(pow_r*prev_val)%M;

                    lim=s_layer[j]-1;

                    prev_val=pow_r;
                    //ans=(ans+(power(m,s_layer[j]-1)*val_s[p])%M)%M;

                    ans=(ans+(pow_r*val_s[p])%M)%M;
                }
    }

    ans=(ans+power(m,n))%M;


    /*for(i=0;i<n+2;i++)
    {
        if(memo[i]==1)
        {
            for(;s_layer[j]==i;j++)
            {
                if(s_layer[j]==0)
                {
                    p1.first=s_layer[j];
                    p1.second=s_vertex[j];
                    p2.first=e_layer[j];
                    p2.second=e_vertex[j];
                    p.first=p1;
                    p.second=p2;
                    ans=(ans+val_s[p])%M;
                }
                else
                {
                    p1.first=s_layer[j];
                    p1.second=s_vertex[j];
                    p2.first=e_layer[j];
                    p2.second=e_vertex[j];
                    p.first=p1;
                    p.second=p2;

                    ans=(ans+(power(m,i-1)*val_s[p])%M)%M;
                }
            }
        }
    }

    ans=(ans+power(m,n))%M;*/

    printf("%lld\n",ans);


    return 0;
}
