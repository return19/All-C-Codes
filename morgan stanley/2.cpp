#include<bits/stdc++.h>
using namespace std;

char c[301000];
char w[301000];

int c_ct[260];
int w_ct[260];

int c_n;
int w_n;

int cc,ww;

int main()
{
    int i,j,k;
    int t,test;
    int n;
    int ans;
    int A,B,C;
    int x,y;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",w);
        scanf("%s",c);

        scanf("%d%d%d",&A,&B,&C);

        memset(c_ct,0,sizeof(c_ct));
        memset(w_ct,0,sizeof(w_ct));

        c_n=strlen(c);
        w_n=strlen(w);

        for(i=0;i<w_n;i++)
            w_ct[w[i]]++;

        for(i=0;i<c_n;i++)
            c_ct[c[i]]++;

        for(i=0;i<259;i++)
        {
            x=min(c_ct[i],w_ct[i]);

            c_ct[i] = c_ct[i]-x;
            w_ct[i] = w_ct[i]-x;
        }

        cc=0;
        ww=0;

        for(i=0;i<259;i++)
        {
            cc+=c_ct[i];
            ww+=w_ct[i];
        }

        ans=0;

        if(ww>cc)
        {
            ans = ans + (ww-cc)*A;
            ww=cc;
        }
        else if(cc>ww)
        {
            ans = ans + (cc-ww)*B;
            cc=ww;
        }

        if((A+B)<C)
        {
            ans =ans + (ww)*(A+B);
        }
        else
        {
            ans = ans + ww*C;
        }

        printf("%d\n",ans);
    }

    return 0;
}







