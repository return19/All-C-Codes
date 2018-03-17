#include<bits/stdc++.h>
using namespace std;
long long pos_c[1000010],C=-1;
long long pos_h[1000010],H=-1;
long long pos_e[1000010],E=-1;
long long pos_f[1000010],F=-1;


long long c[1000010],h[1000010],e[1000010],f[1000010];

char str[1000110];
char str1[2],str2[2];

int main()
{
    long long i,j,k,n,q;
    long long l,r,jj;
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
    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        //scanf("%1c",&a);
        a=getchar_unlocked();
        a=getchar_unlocked();
        b=getchar_unlocked();
        b=getchar_unlocked();
        scanf("%lld%lld",&l,&r);
        l--;
        r--;
        count1=0;
        if(a=='c')
        {
            jj=c[l-1];

            for(j=jj;j<=C;j++)
            {
                if(pos_c[j]<l)
                    continue;
                if(pos_c[j]>r)
                    break;

                x=pos_c[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else if(a=='h')
        {
            jj=h[l-1];

            for(j=jj;j<=H;j++)
            {
                if(pos_h[j]<l)
                    continue;
                if(pos_h[j]>r)
                    break;

                x=pos_h[j];

                if(b=='c')
                {
                    y=c[r]-c[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else if(a=='e')
        {
            jj=e[l-1];

            for(j=jj;j<=E;j++)
            {
                if(pos_e[j]<l)
                    continue;
                if(pos_e[j]>r)
                    break;

                x=pos_e[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='c')
                {
                    y=c[r]-c[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else
        {
            jj=f[l-1];

            for(j=jj;j<=F;j++)
            {
                if(pos_f[j]<l)
                    continue;
                if(pos_f[j]>r)
                    break;

                x=pos_f[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='c')
                {
                    y=c[r]-c[x];
                }

                count1=count1+y;
            }
        }

        printf("%lld\n",count1);
    }

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

long long pos_c[1000010],C=-1;
long long pos_h[1000010],H=-1;
long long pos_e[1000010],E=-1;
long long pos_f[1000010],F=-1;


long long c[1000010],h[1000010],e[1000010],f[1000010];

char str[1000110];

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

    ///////
    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        cin>>l>>r;
        l--;
        r--;
        count1=0;
        if(a=='c')
        {
            for(j=0;j<=C;j++)
            {
                if(pos_c[j]<l)
                    continue;
                if(pos_c[j]>r)
                    break;

                x=pos_c[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else if(a=='h')
        {
            for(j=0;j<=H;j++)
            {
                if(pos_h[j]<l)
                    continue;
                if(pos_h[j]>r)
                    break;

                x=pos_h[j];

                if(b=='c')
                {
                    y=c[r]-c[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else if(a=='e')
        {
            for(j=0;j<=E;j++)
            {
                if(pos_e[j]<l)
                    continue;
                if(pos_e[j]>r)
                    break;

                x=pos_e[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='c')
                {
                    y=c[r]-c[x];
                }
                if(b=='f')
                {
                    y=f[r]-f[x];
                }

                count1=count1+y;
            }
        }
        else
        {
            for(j=0;j<=F;j++)
            {
                if(pos_f[j]<l)
                    continue;
                if(pos_f[j]>r)
                    break;

                x=pos_f[j];

                if(b=='h')
                {
                    y=h[r]-h[x];
                }
                if(b=='e')
                {
                    y=e[r]-e[x];
                }
                if(b=='c')
                {
                    y=c[r]-c[x];
                }

                count1=count1+y;
            }
        }

        printf("%lld\n",count1);
    }

    return 0;
}













*/









