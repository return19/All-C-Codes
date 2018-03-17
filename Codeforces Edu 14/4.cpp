#include<bits/stdc++.h>
using namespace std;

char s[1010000];

int main()
{
    int i,j,k;
    scanf("%s",s);
    int n = strlen(s);

    if(n==1 && s[0]=='0'){
        cout<<"0"<<endl;
        return 0;
    }

    int p=-1;

    for(i=0;i<n;i++)
    {
        if(s[i]=='.')
            p=i;
    }

    if(p==-1){
        i=0;
        while(i<n && s[i]=='0')
            i++;
        int c=n-i-1;
        cout<<s[i++];
        if(i!=n)
            cout<<".";
        j=n-1;
        while(j>=0 && s[j]=='0')
            j--;
        while(i<=j){
            cout<<s[i];
            i++;
        }
        if(c!=0)
            cout<<"E"<<c<<endl;
        return 0;
    }
    i=0;
    j=n-1;
    while(i<n && s[i]=='0')
        i++;
    while(j>=0 && s[j]=='0')
        j--;
    if(i==p){
        int c=1;
        for(i++;i<=j;i++)
            if(s[i]!='0')
                break;
            else
                c++;
        //cout<<i<<" "<<c<<endl;
        if(i>j)
        {
            cout<<0<<endl;
            return 0;
        }

        cout<<s[i];
        if(i<j)
            cout<<".";
        for(i++;i<=j;i++)
            cout<<s[i];
        cout<<"E"<<-1*c<<endl;
        return 0;
    }


    int c=p-i-1;
    cout<<s[i];

   // cout<<p<<" "<<j<<endl;
    if(p==j){
            j--;
        while(j>=0 && s[j]=='0')
            j--;
    }
    if(i!=j)
        cout<<".";
    for(i++;i<p && i<=j;i++)
        cout<<s[i];
    for(i++;i<=j;i++)
        cout<<s[i];
    if(c!=0)
        cout<<"E"<<c<<endl;


    return 0;
}
