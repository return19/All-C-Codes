#include<bits/stdc++.h>
using namespace std;

int dish[10000000][2];
int vil[100000000][3];

map<int,int> d;
map<int,int> v;

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    long long test,i,j,k;

    long long x,b,c;

    long long p,q;
    long long sum=0;

    long long p1,q1,r1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        d.clear();
        v.clear();

        sum=0;
        scanf("%lld",&x);

        scanf("%lld",&b);

        for(j=0;j<b;j++)
        {
            scanf("%lld%lld",&p,&q);

            d[p]=1;
            dish[j+1][0]=p;
            dish[j+1][1]=q;

            sum=sum+q;
        }

        scanf("%lld",&c);

        for(j=0;j<c;j++)
        {
            scanf("%lld%lld%lld",&p1,&q1,&r1);

            v[p1]=1;
            vil[j+1][0]=p1;
            vil[j+1][1]=q1;
            vil[j+1][2]=r1;
        }

        int ms=0,till_sum=0;
        int tot=sum+1;
        int atl=0,atl1=0;

        int V=0;
        int D=0;

        if(c==0){
            printf("%lld\n",sum+1);
            continue;
        }
        else
        {
            for(j=1;j<=x;j++)
            {
                if(D>=b)
                    break;
                if(d[j]==1)
                {
                    tot=tot-dish[++D][1];
                }
                else if(v[j]==1)
                {
                    if(tot>=vil[++V][1])
                    {
                        atl1=atl;
                        atl=max2(dish[D][1]+1,max2(vil[V][1],tot-vil[V][2]));

                        tot=atl;
                        /*if(atl1==atl)
                        {

                        }
                        else
                            ms+=tot-atl;*/
                    }
                }

            }

            cout<<tot<<endl;
        }
    }

    return 0;
}











