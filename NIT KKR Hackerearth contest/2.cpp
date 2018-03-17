#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("output05.txt","w",stdout);

    long long i,j,k;
    long long test,t;
    long long n;
    long long x;
    scanf("%lld",&test);

    for(t=0;t<test;t++){
        long long c=0;
        scanf("%lld%lld",&n,&k);
        long long tn = n;
        for(i=0;i<k;i++){
            scanf("%lld",&x);
            if(!x){
                tn+=2;
            }
            else{
                if(tn==0){
                    cout<<"here"<<endl;
                }
                else if(tn==1){
                    tn=0;
                } else{
                    tn-=2;
                }
            }
           // cout<<c<<endl;
        }

        printf("%lld\n",abs(n*n*n - tn*tn*tn));
    }
    return 0;
}
