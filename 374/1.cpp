#include<bits/stdc++.h>
using namespace std;

char s[101000];
vector<int> ans;
int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    scanf("%s",s);

    i=0;
    int c;
    while(i<n){
        c=0;
        if(s[i]=='B'){
            while(i<n && s[i]=='B'){
                i++;
                c++;
            }
            ans.push_back(c);
            continue;
        }
        i++;
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)
        printf("%d ",ans[i]);


    return 0;
}
