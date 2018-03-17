#include<bits/stdc++.h>
using namespace std;

char s[1010000];
string ans="";

int main()
{
    int i,j,k;
    int w=1,x=1,y=1,z=1; // 1689
    int r=0;

    scanf("%s",s);
    int n=strlen(s);
    int c=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0'){
            c++;
            continue;
        }
        if(s[i]=='1' && w==1){
            w=0;    continue;
        }
        if(s[i]=='6' && x==1){
            x=0;    continue;
        }
        if(s[i]=='8' && y==1){
            y=0;    continue;
        }
        if(s[i]=='9' && z==1){
            z=0;    continue;
        }
        ans.push_back(s[i]);
    }
    if(c==n-4){
        cout<<1869;
        for(i=0;i<c;i++)
            cout<<"0";
        cout<<endl;
        return 0;
    }

    while(c){
        ans.push_back('0');
        c--;
    }

    for(i=0;i<ans.length();i++){
        r=(r*10+ans[i]-'0')%7;
    }


    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(x=0;x<4;x++)
                    if(i!=j && i!=k && i!=x && j!=k && j!=x && k!=x){
                        int temp=1*pow(10,i) + 6*pow(10,j) + 8*pow(10,k) + 9*pow(10,x);
                        if((r*10000 + temp)%7==0){
                            cout<<ans<<temp<<endl;
                            return 0;
                        }
                    }

    return 0;
}







