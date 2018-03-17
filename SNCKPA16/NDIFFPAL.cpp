#include<bits/stdc++.h>
using namespace std;

int n;

vector< vector<int> > v;

vector<int> solve(int x){
    int i,j,k;

    vector<int> ans;

    for(i=n;i<n+2*x;i+=2){
        ans.push_back(i+1);
        ans.push_back(i);
    }

    n=i;

  /*  for(i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;*/
    return ans;
}

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&k);

        v.resize(0);
        n=1;
        int p=1;
        while(k){

                if(k%10==0)
                {
                    k/=10;
                    p++;
                    continue;
                }
                vector<int> temp;
            if(p==1){
                temp.push_back(n);
                n++;
                for(i=k%10;i>0;i--)
                    temp.push_back(n+i-1);
                n+= k%10;
                p++;
            }else{
                for(i=k%10;i>0;i--)
                    temp.push_back(n+i-1);
                n+= k%10;

                for(j=0;j<p-1;j++){
                    for(i=10;i>0;i--){
                        temp.push_back(n+i-1);
                    }
                    n+=10;
                }
                p++;
            }
            v.push_back(temp);
            k/=10;
        }

        int cnt=0;
        for(i=v.size()-1;i>=0;i--){
            for(j=0;j<v[i].size();j++){
                //cout<<v[i][j]<<" ";
                cnt++;
            }
        }
       // cout<<endl;

        cout<<cnt<<endl;

        for(i=v.size()-1;i>=0;i--){
            for(j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
              //  cnt++;
            }
        }

        cout<<endl;

    }
    return 0;
}
