#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

pair<double,double> arr[101000];
map<double,double> l;
map<double,double> r;

map<double,double>::iterator it;

int main()
{
    double i,j,k;
    double n,w,v,u;
    double x,y;
    double mn = 2;

    scanf("%lf%lf%lf%lf",&n,&w,&v,&u);

    for(i=0;i<n;i++){
        scanf("%lf%lf",&x,&y);
        mn = min(mn,x);

        if(l.find(y) == l.end())
            l[y] = x;
        else
            l[y] = min(l[y],x);

        if(r.find(y) == r.end())
            r[y] = x;
        else
            r[y] = max(r[y],x);
    }

    if(mn>=0){
       // cout<<"here"<<endl;
        int f=0;
        double cy=0;
        double ct=0;
        for(it = l.begin();it!=l.end();it++){
            double x,y;
            y = it->first;
            x = it->second;
            double reqTime = (x)/v;
            double canTime = (y)/u;
            if( canTime > reqTime){
                f=1;
                break;
            }
        }
        if(!f){
            printf("%lf\n",w/u);
            return 0;
        }
    }
    //cout<<"here too"<<endl;

    double ct=0;
    double cy=0;

    for(it=r.begin();it!=r.end();it++){
        double y = it->first;
        double x = it->second;

        if(x<0)
            continue;

        //cout<<x<<" "<<y<<endl;

        double reqTime = (x)/v;
        double canTime = (y-cy)/u;

       // cout<<reqTime<<" "<<canTime<<endl;

        ct = max(ct + canTime,reqTime);
        cy = y;
        //cout<<ct<<endl;
    }
    ct += (w-cy)/u;

    printf("%.8lf\n",ct);


    return 0;
}














