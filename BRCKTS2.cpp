#include<bits/stdc++.h>
using namespace std;

char str[1010000];
long long arr[1010000];
long long ed[1010000];
stack<long long> s;
long long n;
long long st[10100000];
void build(long long idx,long long l,long long r){
    if(l>r)
        return;
    if(l==r){
        st[idx]=arr[l];
        return;
    }
    long long mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    st[idx] = max(st[(idx<<1)+1],st[(idx<<1)+2]);
}

long long query(long long idx,long long l,long long r,long long ql,long long qr){
    if(l>r) return 0;
    if(qr<l || r<ql)
        return 0;
    if(ql<=l && r<=qr)
        return st[idx];
    long long mid= l + (r-l)/2;
    return max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",str);
        n=strlen(str);

        x=0;
        for(i=0;i<n;i++){
            if(str[i]=='('){
                x++;
                s.push(i);
            }else{ // str[i]==')'
                x--;
                ed[s.top()]=i;
                s.pop();
            }
            arr[i]=x;
        }

       /* for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
            cout<<ed[i]<<" ";
        cout<<endl;*/

        build(0,0,n-1);

        long long ans=0;
        for(i=0;i<n;i++){
            if(str[i]=='('){
              //  cout<<query(0,0,n-1,i,ed[i])-arr[i]+1<<" "<<ed[i]-i<<endl;
                long long temp = (query(0,0,n-1,i,ed[i]) - arr[i]+1)*(ed[i]-i);

                if(arr[i]%2==0){
                    ans = ans -temp;
               }else
                    ans = ans +temp;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
