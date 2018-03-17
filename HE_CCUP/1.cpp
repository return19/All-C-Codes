#include<bits/stdc++.h>
using namespace std;

char aa[101000];
char bb[101000];
int n;

int cmp(int a,int b,int c,int d){
    int i,j;
    i=a;
    j=c;
    while(i<=b){
        if(aa[i]!=bb[j])  return 0;
        i++;
        j++;
    }
    return 1;
}

int check1(int a,int b,int c,int d){
    int i,j,k;

    if(cmp(a,b,c,d))
        return 1;

    for(i=c;i<d;i++){
        swap(bb[i],bb[i+1]);
       // cout<<aa<<" "<<bb<<endl;
        if(cmp(a,b,c,d)){
            swap(bb[i],bb[i+1]);
            return 1;
        }
        swap(bb[i],bb[i+1]);
    }
    return 0;
}

int check(int a,int b,int c,int d,int x){
    int i,j,k;

    if(b-a != d-c)
        return 0;

    if(x==0){
        if(cmp(a,b,c,d))
            return 1;
        return 0;
    }

    if(cmp(a,b,c,d))
        return 1;

    if(x==1){
        if(check1(a,b,c,d))
            return 1;
        return 0;
    }

    if(check1(a,b,c,d))
            return 1;

    for(i=a;i<b;i++){
        for(j=c;j<d;j++){
            swap(aa[i],aa[i+1]);
            swap(bb[j],bb[j+1]);

            if(cmp(a,b,c,d)){
                swap(bb[j],bb[j+1]);
                swap(aa[i],aa[i+1]);
                return 1;
            }
            swap(bb[j],bb[j+1]);
            swap(aa[i],aa[i+1]);
        }
    }
    return 0;
}

int main()
{
    int i,j,k;
    scanf("%s%s",aa,bb);
    n = strlen(aa);

    int q;
    int a,b,c,d;

    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d%d%d%d%d",&k,&a,&b,&c,&d);
        a--;
        b--;
        c--;
        d--;

        if(check(a,b,c,d,k)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}
