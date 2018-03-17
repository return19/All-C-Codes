#include<bits/stdc++.h>
using namespace std;


char str[100010][15];

int pos1[100010];
int pos2[100010];

int index11[100010];


class bit
{
    long long arr[101010];
    long long n;


    public:

    bit(){}

    bit(long long n)
    {
        this->n=n;
        memset(arr,0,sizeof(long long)*(n+5));
    }

    long long query(long long idx)
    {
        long long sum=0;

        while(idx>0)
        {
            sum+=arr[idx];
            idx=idx-(idx&(-idx));
        }
        return sum;
    }

    void update(long long idx,long long val)
    {
        while(idx<=n)
        {
            arr[idx]+=val;
            idx=idx+(idx&(-idx));
        }
    }
};




long long cmp1(long long a,long long b)
{
    int i=0;
    while(str[a][i]!='\0'&&str[b][i]!='\0')
    {
        if(str[a][i]-'0'<str[b][i]-'0')
            return 1;

        if(str[a][i]-'0'>str[b][i]-'0')
            return 0;

        i++;
    }
      if(str[a][i]=='\0')
    return 1;

    return 0;
}

long long cmp2(long long a,long long b)
{
    return strcmp(str[a],str[b]);
}


void strrev(long long i)
{
    long long k,j;
    long long n=strlen(str[i]);
    char temp;

    for(j=0,k=n-1;j<k;j++,k--)
    {
        temp=str[i][j];
        str[i][j]=str[i][k];
        str[i][k]=temp;
    }
}

bit bt(100100);

int main()
{
    long long n,i,j,k;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%s",str[i]);
        pos1[i]=i;
        pos2[i]=i;
    }



    sort(pos1+1,pos1+n+1,cmp1);


    for(i=1;i<=n;i++)
    {
        strrev(i);
    }


    sort(pos2+1,pos2+n+1,cmp1);


    for(i=1;i<=n;i++)
    {
        index11[pos2[i]]=i;
    }

    long long sum=0;

    for(i=1;i<=n;i++)
    {
        sum+=bt.query(n+5)-bt.query(index11[pos1[i]]);

        bt.update(index11[pos1[i]],1);
    }

    printf("%lld\n",sum);



    return 0;
}
