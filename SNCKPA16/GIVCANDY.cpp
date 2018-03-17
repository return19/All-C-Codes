#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

int main()
{
    long long i,j,k;
    long long test,t;
    long long a,b,c,d;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

        if(c<d){
            d=d%c;
            c=c-d;
        }else if(c>d){ // c>d
            c=c%d;
            d=d-c;
        }else{
            printf("%lld\n",abs(a-b));
            continue;
        }

        long long dif=abs(a-b);
        long long ans;
        if(a<b){
            ans=min(dif%c,c - dif%c);
        }else if(a>b){
            ans=min(dif%d,d - dif%d);
        }else{
            ans=0;
        }

        /*memo.clear();
        long long ans=LLONG_MAX;

        while(memo.find(a-b)==memo.end()){
            ans=min(ans,abs(a-b));

            memo[a-b]=1;

            long long dif=abs(a-b);
            long long m;

            if(a<b){
                m=dif/c +1;

                if(dif%c==0)
                {
                    ans=0;
                    break;
                }

                a += m*c;
            }else{ // b<a
                m=dif/d +1;

                if(dif%d==0)
                {
                    ans=0;
                    break;
                }

                b += m*d;
            }

          //  cout<<a<<" "<<b<<" "<<m<<endl;
        }*/

        printf("%lld\n",ans);
    }
    return 0;
}


//7 13 20 6





