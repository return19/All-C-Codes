#include<bits/stdc++.h>
using namespace std;

string s;

long long check(long long x)
{
    if(x>=-99999 && x<=99999)
        return 1;
    return 0;
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long a,b,c;
    long long x,y,z;
    long long st1,st2,st3;
    long long ed1,ed2,ed3;
    long long n;
    long long op,eq;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        cin>>s;
        n=s.length();

        long long f=0;
        for(i=0;i<n;i++)
        {

            if(s[i]!='-' && f==0)
                f=1;
            else if( f==1 && (s[i]=='+'||s[i]=='-'||s[i]=='*')){
                op=i;
                ed1=i-1;
                f=2;
            }
            else if(s[i]=='='){
                eq=i;
                ed2=i-1;
            }//cout<<i<<" "<<f<<endl;
        }
        ed3=n-1;

        if(s[0]=='-'){
            a=-1;
            st1=1;
        }else{
             a=1;
             st1=0;
        }

        if(s[op+1]=='-'){
            b=-1;
            st2=op+2;
        }else {
            b=1;
            st2=op+1;
        }

        if(s[eq+1]=='-'){
            c=-1;
            st3=eq+2;
        }else {
            st3=eq+1;
            c=1;
        }

       /* cout<<a<<" "<<st1<<" "<<ed1<<endl;
        cout<<b<<" "<<st2<<" "<<ed2<<endl;
        cout<<c<<" "<<st3<<" "<<ed3<<endl;*/
        long long chk1=1,chk2=1,chk3=1;

        for(j=st1;j<=ed1;j++){
                if(s[j]!='?')
                {
                    chk1=0;
                    break;
                }
            }

            for(j=st2;j<=ed2;j++){
                if(s[j]!='?')
                {
                    chk2=0;
                    break;
                }
            }

            for(j=st3;j<=ed3;j++){
                if(s[j]!='?')
               {
                   chk3=0;
                   break;
               }
            }

        for(i=0;i<=9;i++)
        {
            if(i==0)
            {
                if(chk1==0 && st1!=ed1 && s[st1]=='?')
                    continue;
                if(chk2==0 && st2!=ed2 && s[st2]=='?')
                    continue;
                if(chk3==0 && st3!=ed3 && s[st3]=='?')
                    continue;

                if(a==-1 && s[st1]=='?')
                    continue;
                if(b==-1 && s[st2]=='?')
                    continue;
                if(c==-1 && s[st3]=='?')
                    continue;

            }

            x=0;    y=0;    z=0;

            for(j=st1;j<=ed1;j++){
                if(s[j]=='?')
                    x=x*10 + i;
                else
                    x=x*10 + s[j]-'0';
            }

            for(j=st2;j<=ed2;j++){
                if(s[j]=='?')
                    y=y*10 + i;
                else
                    y=y*10 + s[j]-'0';
            }

            for(j=st3;j<=ed3;j++){
                if(s[j]=='?')
                    z=z*10 + i;
                else
                    z=z*10 + s[j]-'0';
            }

            if(check(a*x) && check(b*y) && check(c*z))
                if(s[op]=='+'){
                    if(a*x + b*y == c*z)
                        break;
                }else if(s[op]=='-'){
                    if(a*x - b*y == c*z)
                        break;
                }else{
                    if(a*x * b*y == c*z)
                        break;
                }
        }
        if(i==10)
            printf("-1\n");
        else
            printf("%lld\n",i);
    }
    return 0;
}

















