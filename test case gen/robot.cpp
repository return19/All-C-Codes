#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int test,t;
    int n,m,x;
    string s;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        cin>>s;
        scanf("%d%d%d",&n,&m,&x);

        if(n>=x){
            if(s[0]=='F'){
                printf("1\nTiti\n");
            } else {
                printf("1\nJatin\n");
            }
        } else if(n==m){
            printf("-1\n");
        } else {
            int l;
            if(n>m){
                if(s[0]=='F')
                    l=n;
                else
                    l=n-m;
            }
            if(m>n){
                    l=n;
                if(s[0]=='F'){
                    s[0]='B';
                    l=m-n;
                }
                else
                    s[0]='F';
            }

            int tmp = abs(n-m);
            cout<<l<<endl;
            int y = (2*(x-l))/tmp;
            if((x-l)%tmp!=0)
                y++;
            if(s[0]=='F'){
                printf("%d\nTiti\n",y);
            } else {
                printf("%d\nJatin\n",y);
            }
        }
    }
    return 0;
}
