#include <bits/stdc++.h>
using namespace std ;
#define LL long long int
#define ft first
#define sd second
#define PII pair<int,int>
#define ORDER 5
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define pb push_back
#define MOD 10000003


char A[2222][1111] ;
int B[1111] , X[1111] , Y[1111];

int main(){

    int n ;
    sc(n) ;
    for(int i=1;i<=n;i++){
        sc(B[i]) ;
    }
    for(int i=0;i<2222;i++){
        for(int j=0;j<1111;j++){
            A[i][j] = ' ' ;
        }
    }
    bool f = 0 ;
    int x1 ,y1 , x2 ,y2 , x , y , ans1 , ans2 ;
    x1 = x = 0 ;
    y1 = y = 1111 ;
    ans1 = MOD ;
    ans2 = 0 ;
    for(int i=1;i<=n;i++){
        X[i] = B[i] ;
        X[i] += X[i-1] ;
        Y[i] = Y[i-1] ;
        if(f){
            Y[i] -= B[i] ;
        }else{
            Y[i] += B[i] ;
        }
        x2 = X[i] ;
        y2 = Y[i] ;
        y2 += 1111 ;
        int diff = y2 - y1 ;
        while(diff > 0){
            ans1 = min(ans1,y) ;
            ans2 = max(ans2,y) ;
          //   cout << x << " " << y << endl ;
            A[y][x] = '/' ;
            diff -- ;
            if(diff <= 0) break ;
            y -- ;
            x ++ ;

        }
        while(diff < 0){
            ans1 = min(ans1,y) ;
            ans2 = max(ans2,y) ;
            A[y][x] = '\\' ;
            diff ++ ;
        //    cout << x << " " << y << endl ;
            if(diff >= 0) break ;
            y ++ ;
            x ++ ;

        }
        x ++ ;
        y1 = y2 ;
        x1 = x2 ;
        f = f ^ 1 ;
     }
     for(int i=ans1;i<=ans2;i++){
         for(int j=0;j<=x2;j++){
             cout << A[i][j] ;
         }
         if(i != ans2) cout << endl ;
     }
    return 0 ;
}
