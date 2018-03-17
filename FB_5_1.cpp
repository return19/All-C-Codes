
#include<bits/stdc++.h>
using namespace std;

long long pos_c[1000010],C=-1;
long long pos_h[1000010],H=-1;
long long pos_e[1000010],E=-1;
long long pos_f[1000010],F=-1;


long long c[1000010],h[1000010],e[1000010],f[1000010];

char str[1000110];

void scanint(long long &x)
{
    register long long c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    long long i,j,k,n,q;
    long long l,r;
    char a,b;
    long long x,y,count1=0;

    scanf("%s",str);
    n=0;

    while(str[n]!='\0')
    {
        if(str[n]=='c')
        {
            pos_c[++C]=n;
            c[n]=c[n-1]+1;
            h[n]=h[n-1];
            e[n]=e[n-1];
            f[n]=f[n-1];
        }
        else if(str[n]=='h')
        {
            pos_h[++H]=n;
            c[n]=c[n-1];
            h[n]=h[n-1]+1;
            e[n]=e[n-1];
            f[n]=f[n-1];
        }
        else if(str[n]=='e')
        {
            pos_e[++E]=n;
            c[n]=c[n-1];
            h[n]=h[n-1];
            e[n]=e[n-1]+1;
            f[n]=f[n-1];
        }
        else
        {
            pos_f[++F]=n;
            c[n]=c[n-1];
            h[n]=h[n-1];
            e[n]=e[n-1];
            f[n]=f[n-1]+1;
        }

        n++;
    }

    //////////
    /*for(i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;

     for(i=0;i<n;i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;

     for(i=0;i<n;i++)
    {
        cout<<e[i]<<" ";
    }
    cout<<endl;

     for(i=0;i<n;i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;*/
    ///////
    //scanf("%lld",&q);
    scanint(q);

    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        scanint(l);
        scanint(r);
        l--;
        r--;
        count1=0;
        if(a=='c')
        {
            for(j=l;j<=r;j++)
            {
                /*if(pos_c[j]<l)
                    continue;
                if(pos_c[j]>r)
                    break;
                */
                //x=pos_c[j];
                if(str[j]!='c')
                    continue;


                if(b=='h')
                {
                    y=h[r]-h[j];
                }
                if(b=='e')
                {
                    y=e[r]-e[j];
                }
                if(b=='f')
                {
                    y=f[r]-f[j];
                }

                count1=count1+y;
            }
        }
        else if(a=='h')
        {
            for(j=l;j<=r;j++)
            {
                /*if(pos_h[j]<l)
                    continue;
                if(pos_h[j]>r)
                    break;*/

                //x=pos_h[j];
                if(str[j]!='h')
                    continue;

                if(b=='c')
                {
                    y=c[r]-c[j];
                }
                if(b=='e')
                {
                    y=e[r]-e[j];
                }
                if(b=='f')
                {
                    y=f[r]-f[j];
                }

                count1=count1+y;
            }
        }
        else if(a=='e')
        {
            for(j=l;j<=r;j++)
            {
                /*if(pos_e[j]<l)
                    continue;
                if(pos_e[j]>r)
                    break;*/

                //x=pos_e[j];

                if(str[j]!='e')
                    continue;

                if(b=='h')
                {
                    y=h[r]-h[j];
                }
                if(b=='c')
                {
                    y=c[r]-c[j];
                }
                if(b=='f')
                {
                    y=f[r]-f[j];
                }

                count1=count1+y;
            }
        }
        else
        {
            for(j=l;j<=r;j++)
            {
                /*if(pos_f[j]<l)
                    continue;
                if(pos_f[j]>r)
                    break;*/

                //x=pos_f[j];

                if(str[j]!='f')
                    continue;

                if(b=='h')
                {
                    y=h[r]-h[j];
                }
                if(b=='e')
                {
                    y=e[r]-e[j];
                }
                if(b=='c')
                {
                    y=c[r]-c[j];
                }

                count1=count1+y;
            }
        }

        printf("%lld\n",count1);
    }

    return 0;
}












