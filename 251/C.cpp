#include<bits/stdc++.h>

using namespace std;

int a[200000];
vector<int> even;
vector<int> odd;
int main()
{
    int n,k,p;
    int e,o;
    e=o=0;

    int t1=0;

    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]&1){
            o++;
            odd.push_back(a[i]);
        }
        else{
            e++;
            even.push_back(a[i]);
        }
    }

    int le=e;
    int lo=o;

    if(p<=e)
        le = e-p;
    else
    {
        if(o>=2*(p-e))
        {
            le = 0;
            lo = o - 2*(p-e);
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }


    if(k-p<=lo)
    {
        lo = lo-(k-p);

        if(lo&1){
            printf("NO\n");
            return 0;
        }
    }
    else
    {
        printf("NO\n");
        return 0;
    }


    printf("YES\n");
    int sp;
    sp = p;
    vector<int>::iterator ite;
    vector<int>::iterator ito;
    vector<int>::iterator ite1;
    vector<int>::iterator ito1;


   /* for(ito = odd.begin();sp>0;ito+=2){
        printf("2 %d %d\n",*ito,*(ito+1)):
        sp--;
    }
    */
    if(p==k){

        sp = k;

        for(ite = even.begin();ite!=even.end() && sp-1>0;ite++){
        printf("1 %d\n",*ite);
        sp--;
        }

        for(ito = odd.begin();sp-1>0;ito+=2){
        printf("2 %d %d\n",*ito,*(ito+1));
        sp--;
        }

        ite1=ite;
        ito1=ito;



        t1=0;

        for(;ite!=even.end();ite++)
            t1++;

        for(ito = odd.begin();ito!=odd.end();ito++)
            t1++;

        printf("%d ",t1);
        for(;ite!=even.end();ite++)
            printf("%d ",*ite);

        for(ito = odd.begin();ito!=odd.end();ito++)
            printf("%d ",*ito);

        printf("\n");
    }

    else if(p==0)
    {
        sp = k;
        for(ito = odd.begin();sp-1>0;ito++){
        printf("1 %d\n",*ito);
        sp--;
        }

        printf("%d ",le+1+lo);
        for(;ito!=odd.end();ito++)
            printf("%d ",*ito);

        for(ite = even.begin();ite!=even.end();ite++)
            printf("%d ",*ite);

        printf("\n");
    }
    else{
        sp = p;
        ite = even.begin();
        for(;ite!=even.end() && sp>0;ite++){
        printf("1 %d\n",*ite);
        sp--;
        }
        ito = odd.begin();
        for(;sp>0;ito+=2){
        printf("2 %d %d\n",*ito,*(ito+1));
        sp--;
        }

        sp = k-p;

        for(;ito!=odd.end() && sp-1>0;ito++){
        printf("1 %d\n",*ito);
        sp--;
        }

        printf("%d ",le+1+lo);
        for(;ito!=odd.end();ito++)
            printf("%d ",*ito);

        for(;ite!=even.end();ite++)
            printf("%d ",*ite);

        printf("\n");


    }

    return 0;
}
