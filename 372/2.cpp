#include<bits/stdc++.h>
using namespace std;

int c[26];
char s[50100];

int main()
{
    int i,j,k;
    scanf("%s",s);
    int n = strlen(s);

    int q=0;
    i=0;
    for(j=0;j<n;j++){
        if(s[j]!='?')
            c[ s[j] - 'A' ]++;

        if(s[j] !='?' && c[s[j] - 'A'] > 1){
            while(i<=j && c[s[j] - 'A'] > 1)
            {
                if(s[i]=='?'){
                    q--;
                }else{
                    c[s[i]-'A']--;
                }
                i++;
            }
        }

        if(s[j]=='?')
            q++;


        int cur =0;
        string ans ="";
        for(k=0;k<26;k++){
            cur += c[k];

            if(c[k]==0)
                ans.push_back('A'+k);
        }
        if(26-cur == q){
            int x=0;
            for(k=i;k<=j;k++)
            {
                if(s[k]=='?'){
                    if(x<ans.length())
                        s[k] = ans[x++];
                    else
                        s[k] = 'A';
                }
            }

            for(k=0;k<n;k++)
                if(s[k]=='?')
                    s[k]='A';
            cout<<s<<endl;
            return 0;
        }

    }
    cout<<"-1"<<endl;

    return 0;
}
