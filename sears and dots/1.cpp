#include<bits/stdc++.h>
using namespace std;

int arr[101000];
int s[1010000];
vector<int> p;
int pf[1010000];
void sieve(){
    int i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=1000010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=1000010;j+=i)
                s[j]=1;
        }
    }
}

int main()
{
    int i,j,k;
    int test,t;
    int n;
    sieve();
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<=1000010;i++)
            pf[i]=0;

        for(i=0;i<n;i++){
            int temp = arr[i];
            for(j=0;p[j]*p[j]<=temp;j++){
                int c=0;
                while(temp%p[j]==0){
                    c++;
                    temp/=p[j];
                }
                pf[p[j]]=max(pf[p[j]],c);
            }
            if(temp>1)
                pf[temp] = max(pf[temp],1);
        }

        int f=0;
        for(i=0;p[i]*p[i]<=k;i++){
            int c=0;
            while(k%p[i]==0){
                c++;
                k/=p[i];
            }
            if(pf[p[i]]<c){
                f=1;
                break;
            }
        }

        if(k>1 && pf[k]<1)
            f=1;
        if(f==0){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}











