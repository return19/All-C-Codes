#include<bits/stdc++.h>
using namespace std;

int n;
int s[101000];
int st=1,ed=1000;
vector<int> tests;

void gen_reg_test(){
    int i,j,k;

    tests.push_back(st);
    tests.push_back(st+1);
    tests.push_back((st+ed)/2);
    tests.push_back(ed-1);
    tests.push_back(ed);

    for(i=500;i<=1000;i++)
    {
        if(!s[i]) // prime
            tests.push_back(i);
    }
}

void sieve(){
    int i,j,k;
    s[0]=s[1]=1;

    for(i=0;i<101000;i++){
        if(s[i]==0)
        {
            k=2;
            for(j=i*2;j<101000;j=i*k){
                s[j]=1;
                k++;
            }
        }
    }

    /*for(i=0;i<100;i++){
        if(!s[i])
            cout<<i<<" ";
    }*/
}

int main()
{
    int i,j,k;

    sieve();
    gen_reg_test();

    for(i=0;i<tests.size();i++){
        printf("%d\t:\t",tests[i]);
        if(s[tests[i]])
            printf("Not a prime\n");
        else
            printf("Prime\n");
    }

    /*int sr=sqrt(n);

    for(i=2;i<=sr;i++){
        if(n%i==0)
            break;
    }

    if(i>sr)
    {
        printf("Prime number\n");
    }else{
        printf("Not a prime number\n");
    }*/

    return 0;
}
