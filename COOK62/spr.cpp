#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long test,i,j,k;

    unsigned long long l,r;
    unsigned long long x,y,z;
    unsigned long long t;
    unsigned long long cnt=0;
    unsigned long long temp;

    scanf("%llu",&test);

    for(t=0;t<test;t++)
    {
        scanf("%llu%llu",&l,&r);

        x=1;

        cnt=0;

        for(x=2;x<=ULLONG_MAX&&x<=r;x=x*2)
        {


            for(y=1;y<=ULLONG_MAX&&x*y<=r;y=y*3)
            {
                temp=ULLONG_MAX/y;

                if(x>temp)
                    break;

                if(x*y>=l&&x*y<=r)
                    cnt++;
            }
        }

        if(l==1)
            cnt++;

        printf("%llu\n",cnt);
    }

    return 0;
}
