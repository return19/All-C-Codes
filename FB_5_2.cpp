/*
Author : Abhinandan sharma
*/

#include<bits/stdc++.h>
using namespace std;

char str[1000100];

long long c_h_cm[1000100],c_e_cm[1000100],c_f_cm[1000100];     //cummulative sum type
long long h_c_cm[1000100],h_e_cm[1000100],h_f_cm[1000100];
long long e_h_cm[1000100],e_c_cm[1000100],e_f_cm[1000100];
long long f_h_cm[1000100],f_e_cm[1000100],f_c_cm[1000100];



long long no_of_c[1000100],no_of_h[1000100],no_of_e[1000100],no_of_f[1000100];  //no of chars till pos
long long C=0,H=0,E=0,F=0;

long long c_c=0,h_c=0,e_c=0,f_c=0;

long long c_cnt=0,h_cnt=0,e_cnt=0,f_cnt=0;




int main()
{
    long long n,i,j,k,q,l,r,count1=0;
    long long x,y,ans,t;
    char a,b;

    no_of_c[0]=0;
    no_of_h[0]=0;
    no_of_e[0]=0;
    no_of_f[0]=0;

    scanf("%s",str);

    i=0;    n=0;
    while(str[i]!='\0')
    {
        if(str[i]=='c')
        {
            no_of_c[++C]=no_of_c[C-1]+1;
            no_of_h[++H]=no_of_h[H-1];
            no_of_e[++E]=no_of_e[E-1];
            no_of_f[++F]=no_of_f[F-1];
            c_cnt++;
        }
        else if(str[i]=='h')
        {
            no_of_h[++H]=no_of_h[H-1]+1;
            no_of_c[++C]=no_of_c[C-1];
            no_of_e[++E]=no_of_e[E-1];
            no_of_f[++F]=no_of_f[F-1];
            h_cnt++;
        }
        else if(str[i]=='e')
        {
            no_of_e[++E]=no_of_e[E-1]+1;
            no_of_h[++H]=no_of_h[H-1];
            no_of_c[++C]=no_of_c[C-1];
            no_of_f[++F]=no_of_f[F-1];
            e_cnt++;
        }
        else
        {
            no_of_f[++F]=no_of_f[F-1]+1;
            no_of_h[++H]=no_of_h[H-1];
            no_of_e[++E]=no_of_e[E-1];
            no_of_c[++C]=no_of_c[C-1];
            f_cnt++;
        }

        n++;
        i++;
    }

    //printf("%d\n",n);



    ///////////

    /*for(i=0;i<n;i++)
    {
        printf("%d ",no_of_c[i]);
    }
    printf("\n");*/
    ///////////

    for(i=0;i<n;i++)
    {
        if(str[i]=='c')
        {
            c_h_cm[++c_c]=h_cnt-h_c;
            c_h_cm[c_c]=c_h_cm[c_c-1]+c_h_cm[c_c];

            c_e_cm[c_c]=e_cnt-e_c;
            c_e_cm[c_c]=c_e_cm[c_c]+c_e_cm[c_c-1];

            c_f_cm[c_c]=f_cnt-f_c;
            c_f_cm[c_c]=c_f_cm[c_c]+c_f_cm[c_c-1];

        }
        else if(str[i]=='h')
        {
            h_c_cm[++h_c]=c_cnt-c_c;
            h_c_cm[h_c]=h_c_cm[h_c-1]+h_c_cm[h_c];

            h_e_cm[h_c]=e_cnt-e_c;
            h_e_cm[h_c]=h_e_cm[h_c]+h_e_cm[h_c-1];

            h_f_cm[h_c]=f_cnt-f_c;
            h_f_cm[h_c]=h_f_cm[h_c]+h_f_cm[h_c-1];
        }
        else if(str[i]=='e')
        {
            e_h_cm[++e_c]=h_cnt-h_c;
            e_h_cm[e_c]=e_h_cm[e_c-1]+e_h_cm[e_c];

            e_c_cm[e_c]=c_cnt-c_c;
            e_c_cm[e_c]=e_c_cm[e_c]+e_c_cm[e_c-1];

            e_f_cm[e_c]=f_cnt-f_c;
            e_f_cm[e_c]=e_f_cm[e_c]+e_f_cm[e_c-1];
        }
        else
        {
            f_h_cm[++f_c]=h_cnt-h_c;
            f_h_cm[f_c]=f_h_cm[f_c-1]+f_h_cm[f_c];

            f_e_cm[f_c]=e_cnt-e_c;
            f_e_cm[f_c]=f_e_cm[f_c]+f_e_cm[f_c-1];

            f_c_cm[f_c]=c_cnt-c_c;
            f_c_cm[f_c]=f_c_cm[f_c]+f_c_cm[f_c-1];
        }
    }

    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        a=getchar_unlocked();
        a=getchar_unlocked();
        b=getchar_unlocked();
        b=getchar_unlocked();

        scanf("%lld%lld",&l,&r);
        count1=0;

        if(a=='c')
        {
            if(b=='h')
            {
                x=no_of_c[l-1];
                y=no_of_c[r];
                t=c_h_cm[y]-c_h_cm[x];
                ans=t-(y-x)*(h_cnt-no_of_h[r]);

                count1=count1+ans;
            }
            else if(b=='e')
            {
                x=no_of_c[l-1];
                y=no_of_c[r];
                t=c_e_cm[y]-c_e_cm[x];
                ans=t-(y-x)*(e_cnt-no_of_e[r]);

                count1=count1+ans;
            }
            else // case for f
            {
                x=no_of_c[l-1];
                y=no_of_c[r];
                t=c_f_cm[y]-c_f_cm[x];
                ans=t-(y-x)*(f_cnt-no_of_f[r]);

                count1=count1+ans;
            }

        }
        else if(a=='h')
        {
            if(b=='c')
            {
                x=no_of_h[l-1];
                y=no_of_h[r];
                t=h_c_cm[y]-h_c_cm[x];
                ans=t-(y-x)*(c_cnt-no_of_c[r]);

                count1=count1+ans;
            }
            else if(b=='e')
            {
                x=no_of_h[l-1];
                y=no_of_h[r];
                t=h_e_cm[y]-h_e_cm[x];
                ans=t-(y-x)*(e_cnt-no_of_e[r]);

                count1=count1+ans;
            }
            else // case for f
            {
                x=no_of_h[l-1];
                y=no_of_h[r];
                t=h_f_cm[y]-h_f_cm[x];
                ans=t-(y-x)*(f_cnt-no_of_f[r]);

                count1=count1+ans;
            }
        }
        else if(a=='e')
        {
            if(b=='h')
            {
                x=no_of_e[l-1];
                y=no_of_e[r];
                t=e_h_cm[y]-e_h_cm[x];
                ans=t-(y-x)*(h_cnt-no_of_h[r]);

                count1=count1+ans;
            }
            else if(b=='c')
            {
                x=no_of_e[l-1];
                y=no_of_e[r];
                t=e_c_cm[y]-e_c_cm[x];
                ans=t-(y-x)*(c_cnt-no_of_c[r]);

                count1=count1+ans;
            }
            else // case for f
            {
                x=no_of_e[l-1];
                y=no_of_e[r];
                t=e_f_cm[y]-e_f_cm[x];
                ans=t-(y-x)*(f_cnt-no_of_f[r]);

                count1=count1+ans;
            }
        }
        else
        {
            if(b=='h')
            {
                x=no_of_f[l-1];
                y=no_of_f[r];
                t=f_h_cm[y]-f_h_cm[x];
                ans=t-(y-x)*(h_cnt-no_of_h[r]);

                count1=count1+ans;
            }
            else if(b=='e')
            {
                x=no_of_f[l-1];
                y=no_of_f[r];
                t=f_e_cm[y]-f_e_cm[x];
                ans=t-(y-x)*(e_cnt-no_of_e[r]);

                count1=count1+ans;
            }
            else // case for c
            {
                x=no_of_f[l-1];
                y=no_of_f[r];
                t=f_c_cm[y]-f_c_cm[x];
                ans=t-(y-x)*(c_cnt-no_of_c[r]);

                count1=count1+ans;
            }
        }

        printf("%lld\n",count1);
    }

    return 0;
}












