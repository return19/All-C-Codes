#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ft first
#define sd second

vector< vector<int> > bva_gen(int x,int y,int a,int b,int p,int q){
    int i,j,k;

    vector< vector<int> > v;
    v.resize(4*3 +1);
    int val1,val2;
    k=0;

    for(i=0;i<4*3 + 1;i++){
        v[i].resize(3);
        for(j=0;j<3;j++){
            if(j==0){
                v[i][j]=(x+y)/2;
            }else if(j==1){
                v[i][j]=(a+b)/2;
            }else{
                v[i][j]=(p+q)/2;
            }
        }
    }

    for(i=0;i<3;i++){

        if(i==0){
            val1=x;
            val2=y;
        }else if(i ==1){
            val1=a;
            val2=b;
        }else{
            val1=p;
            val2=q;
        }

        v[k++][i]=val1;
        v[k++][i]=val1+1;
        v[k++][i]=val2-1;
        v[k++][i]=val2;
    }

    return v;
}

vector< vector<int> > robust_gen(int x,int y,int a,int b,int p,int q){
    int i,j,k;

    vector< vector<int> > v;
    v.resize(6*3 +1);
    int val1,val2;
    k=0;

    for(i=0;i<6*3 + 1;i++){
            v[i].resize(3);
        for(j=0;j<3;j++){
            if(j==0){
                v[i][j]=(x+y)/2;
            }else if(j==1){
                v[i][j]=(a+b)/2;
            }else{
                v[i][j]=(p+q)/2;
            }
        }
    }

    for(i=0;i<3;i++){

        if(i==0){
            val1=x;
            val2=y;
        }else if(i ==1){
            val1=a;
            val2=b;
        }else{
            val1=p;
            val2=q;
        }

        v[k++][i]=val1;
        v[k++][i]=val1+1;
        v[k++][i]=val1-1;
        v[k++][i]=val2+1;
        v[k++][i]=val2-1;
        v[k++][i]=val2;
    }

    return v;
}

vector< vector<int> > worst_gen(int x,int y,int a,int b,int p,int q){

    int i,j,k;

    vector< vector<int> > v;

    vector<int> one,two,three;

    one.push_back(x);
    one.push_back(x+1);
    one.push_back((x+y)/2);
    one.push_back(y-1);
    one.push_back(y);

    two.push_back(a);
    two.push_back(a+1);
    two.push_back((a+b)/2);
    two.push_back(b-1);
    two.push_back(b);

    three.push_back(p);
    three.push_back(p+1);
    three.push_back((p+q)/2);
    three.push_back(q-1);
    three.push_back(q);


    for(i=0;i<one.size();i++){
        for(j=0;j<two.size();j++){
            for(k=0;k<three.size();k++){
                vector<int> temp;
                temp.resize(3);
                temp[0]=one[i];
                temp[1]=two[j];
                temp[2]=three[k];
                v.push_back(temp);
                //v.push_back(make_pair(make_pair(one[i],two[j]),three[k]));
            }
        }
    }

    return v;
}


int power(int x,int y,int M){

    if(x<0){
        while(x<0)
            x+=M;
    }

    if(y==0)
        return 1;
    if(y==1)
    {
        return x%M;
    }

    int hf=power(x,y/2,M);

    if(y&1)
        return (((hf*hf)%M)*x)%M;
    return (hf*hf)%M;
}

int main()
{
    int i,j,k;

    vector< vector<int> > v;
    /////////////  boundary value
    v=bva_gen(50,100,1,10,100,200);

    for(i=0;i<v.size();i++){
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"\t"; // use tabs for better gui
        }
        cout<<power(v[i][0],v[i][1],v[i][2]); // answer
        cout<<endl;
    }

    cout<<endl;
    ////////////

    //////// robustness tests

    v=robust_gen(50,100,1,10,100,200);

    for(i=0;i<v.size();i++){
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<power(v[i][0],v[i][1],v[i][2]); // answer
        cout<<endl;
    }

    cout<<endl;

    /////////////

    ////////// worst case tests

    v=worst_gen(50,100,1,10,100,200);
    k=1;
    for(i=0;i<v.size();i++){
            cout<<k++<<"\t:\t";
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<power(v[i][0],v[i][1],v[i][2]); // answer
        cout<<endl;
    }
    cout<<endl;

    /////////////

    return 0;
}










