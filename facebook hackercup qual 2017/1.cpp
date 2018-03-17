#include<bits/stdc++.h>
using namespace std;

double pi = 3.14159265359;

double degree(double x){
    return (x*pi)/180.0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,j,k;
    int test,t;
    double p;
    double x,y;
    double prec = 0.0000001;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        //scanf("%lf%lf%lf",&p,&x,&y);
        cin>>p>>x>>y;
        x -=50;
        y-=50;
        double angle = 3.6*p;

        if(p == 0 || (sqrt( x*x + y*y ) - 50.0 > prec )){
            printf("Case #%d: white\n",t+1);
            continue;
        }

        if(p==100){
            printf("Case #%d: black\n",t+1);
            continue;
        }

        if(x == 0 && y >=0){
            printf("Case #%d: black\n",t+1);
        } else if(x == 0 && y < 0 ){
            if(p>=50)
                printf("Case #%d: black\n",t+1);
            else
                printf("Case #%d: white\n",t+1);
        } else if(y==0 && x>=0){
            if(p>=25)
                printf("Case #%d: black\n",t+1);
            else
                printf("Case #%d: white\n",t+1);
        } else if(y == 0 && x < 0){
            if(p>=75)
                printf("Case #%d: black\n",t+1);
            else
                printf("Case #%d: white\n",t+1);
        } else {

            if(p==25){
                if(x>=0 && y>=0)
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
                continue;
            }

            if(p==50){
                if(x>=0)
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
                continue;
            }

            if(p==75){
                if(x<0 && y>0)
                    printf("Case #%d: white\n",t+1);
                else
                    printf("Case #%d: black\n",t+1);
                continue;
            }

            double a = abs(x);
            double b = abs(y);
            if(p<25){
                if( (a/b) - tan(degree(angle)) < prec )
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
            } else if(p>25 && p<50){
                if( (b/a) - tan(degree(angle-90)) < prec )
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
            } else if(p>50 && p<75){
                if( (a/b) - tan(degree(angle-180)) < prec )
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
            } else {
                if((b/a)- tan(degree(angle-270)) < prec)
                    printf("Case #%d: black\n",t+1);
                else
                    printf("Case #%d: white\n",t+1);
            }

        }

    }
    return 0;
}















