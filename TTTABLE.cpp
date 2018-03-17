#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int dh;
    int dm;
    int ah;
    int am;
    int type;
    int tk;
};

elem arr[1100];

int cmp(elem a,elem b)
{
    if(a.dh==b.dh&&a.dm==b.dm)
    {
        if(a.ah==b.ah)
            return a.am<b.am;
        return a.ah<b.ah;
    }

    if(a.dh==b.dh)
        return a.dm<b.dm;
    return a.dh<b.dh;
}

int comes_after(elem x,elem y,int t)
{
    y.am+=t;
    y.ah += y.am/60;
    y.am = y.am%60;

    //cout<<y.ah<<" "<<y.am<<" as "<<x.dh<<" "<<x.dm<<endl;

    if(x.dh>y.ah||(x.dh==y.ah&&x.dm>=y.am)){
        //cout<<"here  1"<<endl;
        return 1;
    }

    //cout<<"here  2"<<endl;

    return 0;
}

int main()
{
    int test,i,j,k;

    int t,a,b;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&t);

        scanf("%d%d",&a,&b);

        for(j=0;j<a;j++)
        {
            scanf("%d:%d %d:%d",&arr[j].dh,&arr[j].dm,&arr[j].ah,&arr[j].am);


            arr[j].type=1;
            arr[j].tk=0;
        }

        for(;j<a+b;j++)
        {
            scanf("%d:%d %d:%d",&arr[j].dh,&arr[j].dm,&arr[j].ah,&arr[j].am);


            arr[j].type=2;
            arr[j].tk=0;
        }

        sort(arr,arr+a+b,cmp);

        /*for(j=0;j<a+b;j++)
        {
            cout<<arr[j].dh<<":"<<arr[j].dm<<" "<<arr[j].ah<<":"<<arr[j].am<<endl;
        }*/

        int ans1=0;
        int ans2=0;

        for(j=0;j<a+b;j++)
        {
            if(arr[j].tk==1)
                continue;

            if(arr[j].type==1)
                ans1++;
            else
                ans2++;

            arr[j].tk=1;

            elem temp;

            temp=arr[j];

            for(k=0;k<a+b;k++)
            {
                if(arr[k].tk==0&&arr[k].type!=temp.type)
                {
                    if(comes_after(arr[k],temp,t)==1)
                    {
                        arr[k].tk=1;
                        temp=arr[k];
                    }
                }
            }
        }

        printf("Case #%d: %d %d\n",i+1,ans1,ans2);
    }

    return 0;
}










