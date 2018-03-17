#include<bits/stdc++.h>
using namespace std;

char str[101000];

stack<string> s;
char a[10];
int main()
{
     freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);

    int i,j,k;

    while(scanf("%[^\n]s",str)!=EOF){
       getchar();

       // printf("hello : %s\n",str);

        int n = strlen(str);
        string t="";
        for(i=0;i<n;i++){

            if(str[i]==' ' && t=="")
                continue;

            if(str[i]!=' '){
                t.push_back(str[i]);
            } else{
                if(s.empty() || (s.top()!=t)){
                    s.push(t);
                }else{
                    s.pop();
                }
                t="";
            }
        }

        if(t!=""){
             if(s.empty() || (s.top()!=t)){
                s.push(t);
            }else{
                s.pop();
            }
        }

        printf("%d\n",s.size());
        while(!s.empty())   s.pop();
    }
    return 0;
}






