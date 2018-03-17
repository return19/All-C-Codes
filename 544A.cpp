#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
char str[110];
int c[300];

int main()
{
    int i,j,k;
    scanf("%d",&k);
    scanf("%s",str);

    int n = strlen(str);

    string t="";
    for(i=0;i<n;i++){
        if(c[ str[i] ] == 0){
            c[str[i]]=1;
            if(t!="")
                ans.push_back(t);
            t="";
            t.push_back(str[i]);
            k--;
            //cout<<i<<" : "<<k<<endl;
        } else {
            t.push_back(str[i]);
        }

        if(k==0){
            i++;
            while(i<n){
                t.push_back(str[i]);
                i++;
            }
            ans.push_back(t);
        }
    }

    if(k==0){
        printf("YES\n");
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    } else {
        printf("NO\n");
    }

    return 0;
}
