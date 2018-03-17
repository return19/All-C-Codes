#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

vector<int> p;
int s[101000];

int cnt[1010000];

vector< int > arr[101000];

void sieve(){
    int i,j,k;
    s[0]=s[1]=1;

    for(i=2;i<1010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<1010;j+=i){
                s[j]=1;
            }
        }
    }
}

int main(){
    int i,j,k;
    int n;
    int test,t;
    int x;
    scanf("%d",&test);

    sieve();

    for(t=0;t<test;t++){
        scanf("%d",&n);

        //memset(cnt,0,sizeof(cnt));

        for(i=0;i<1010000;i++)
            cnt[i]=0;

        for(i=0;i<n;i++)
            arr[i].resize(0);

        for(i=0;i<n;i++){
            scanint(x);

            int temp=x;

            for(j=0;j<p.size();j++){
                if(temp%p[j]==0){
                    arr[i].push_back(p[j]);
                    while(temp%p[j]==0){
                        temp = temp/p[j];
                    }
                }
            }

            if(temp>1){
                //cout<<"here"<<endl;
                arr[i].push_back(temp);
            }
        }

        /*for(i=0;i<n;i++)
        {
            for(j=0;j<arr[i].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/

        int st=0;
        int ans=0;

        for(i=0;i<n;i++){
            for(j=0;j<arr[i].size();j++){
                cnt[arr[i][j]]++;

                if(cnt[arr[i][j]]>1){
                    while(cnt[arr[i][j]]>1){
                        for(k=0;k<arr[st].size();k++){
                            cnt[arr[st][k]]--;
                        }
                        st++;
                    }
                }
            }

            ans=max(ans,i-st+1);
        }

        if(ans>1)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }

    return 0;
}

















