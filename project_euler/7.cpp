#include<bits/stdc++.h>
using namespace std;

vector<int> p;

int s[500100];

void sieve()
{
    int i,j,k;
    int c=0;

    s[0]=s[1]=1;

    for(i=2;i<500010;i++)
    {
        if(s[i]==0)
        {
            p.push_back(i);
            c++;

            if(c==10005){
                //cout<<"here"<<endl;
                break;
            }

            k=2;

            for(j=i*2;j<500010;j=i*k)
            {
                s[j]=1;

                k++;
            }
        }
    }

    //cout<<p.size()<<endl;
}

int main()
{
    int test,i,j,k,t;

    int n;

    scanf("%d",&test);

    sieve();

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        printf("%d\n",p[n-1]);
    }

    return 0;
}
