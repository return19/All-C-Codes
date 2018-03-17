#include<iostream>
using namespace std;

struct tree
{
    int n,nid[30],nsum[30];
};

int main()
{
    tree t[50];
    int t1,i,j,a[50],sum_id,sum_chld;
    cin>>t1;
    for(i=0;i<t1;i++)
    {
        cin>>t[i].n;

        sum_chld=0;

        sum_id=0;
        for(j=0;j<t[i].n;j++)
        {
            cin>>t[i].nid[j];
            cin>>t[i].nsum[j];

            sum_chld+=t[i].nsum[j];
            sum_id+=t[i].nid[j];
        }
        a[i]=sum_id-sum_chld;
    }

    for(i=0;i<t1;i++)
        cout<<a[i]<<endl;

return 0;
}
