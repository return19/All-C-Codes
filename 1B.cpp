#include<bits/stdc++.h>
using namespace std;

char str[110];

int main()
{
    long long i,j,k;
    long long n;

    long long r,c;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",str);

        int f=0;


        if(str[0]=='R'&&str[1]>=48&&str[1]<=57)
        {
            j=2;
            while(str[j]!='\0')
            {
                if(str[j]=='C')
                    f=1;

                j++;
            }
        }

        if(f==1)
        {
            r=0;
            c=0;

            j=1;

            while(str[j]!='C')
            {
                r=r*10 + str[j]-'0';
                j++;
            }

            j++;

            while(str[j]!='\0')
            {
                c=c*10 + str[j]-'0';
                j++;
            }

            string s;

            while(c!=0)
            {
                if(c%26!=0)
                    s.push_back(c%26 + 65 - 1);
                else
                    s.push_back(26 + 65 - 1);

                if(c%26==0)
                    c=c/26 - 1;
                else
                    c=c/26;
            }

            for(j=0,k=s.length()-1;j<k;j++,k--)
                swap(s[j],s[k]);

            cout<<s<<r<<endl;
        }
        else
        {
            r=0;
            c=0;

            j=0;

            while(str[j]>=65&&str[j]<=90)
            {
                c=c*26 + str[j] - 'A' + 1;
                j++;
            }

            cout<<"R";

            while(str[j]!='\0')
                cout<<str[j++];
            cout<<"C";

            cout<<c<<endl;
        }
    }

    return 0;
}









