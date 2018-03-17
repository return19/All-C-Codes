#include<bits/stdc++.h>
using namespace std;

int n;

vector<string> v;

char str[110];

string s;

int cmp(string a,string b)
{
    int al,bl;

    al=a.length();
    bl=b.length();

    int i,j,k;

    for(i=0;i<al&&i<bl;i++)
    {
        if(a[i]<b[i])
            return 1;
        else if(a[i]>b[i])
            return 0;
    }

    if(al==bl)
    {
        return 0;
    }
    else if(al<bl)
        return 1;
    return 0;
}

int main()
{
    int test,t,i,j,k;
    int l;

    char ch;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        v.resize(0);

        for(i=0;i<n;i++)
        {
            ch=getchar();
            scanf("%[^\n]s",str);

            l=strlen(str);

            //printf("%s\n",str);

            s="";

            for(j=0;j<l;j++)
                s.push_back(str[j]);

            v.push_back(s);
        }

        /*cout<<"here"<<endl;

        for(i=0;i<n;i++)
            cout<<v[i]<<endl;*/

        int ans=0;

        for(i=1;i<n;i++)
        {
            if(cmp(v[i],v[i-1]))
            {
                swap(v[i],v[i-1]);
                ans++;
            }
        }

        printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}









