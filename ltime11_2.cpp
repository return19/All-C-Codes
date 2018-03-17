#include<bits/stdc++.h>
using namespace std;

int arr[20110];

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int main()
{
    int test,i,j,k,n;
    int a,b,sq;
    int c1,c2,t_a,t_b;
    int dmin;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }

        b=arr[0];
        a=1;
        for(j=1;j<n;j++)
        {

            a=b*a;
            b=arr[j];
            cout<<a<<" "<<b<<endl;
            sq=(min2(a,b));
            for(k=2;k<=sq;k++)
            {
                if(a%k!=0||b%k!=0)
                    continue;
                c1=0;   c2=0;
                t_a=a;  t_b=b;
                while(t_a%k==0)
                {
                    t_a=t_a/k;
                    c1++;
                }
                while(t_b%k==0)
                {
                    t_b=t_b/k;
                    c2++;
                }
                dmin=min2(c1,c2);
                a=a/(k*dmin);
                b=b/(k*dmin);
            }
        }
        cout<<a<<" "<<b<<endl;
        printf("%d\n",(a*b)%1000000007);
    }
    return 0;
}
