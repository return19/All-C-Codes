#include<bits/stdc++.h>
using namespace std;

list<int> l;
list<int>::iterator it1,it2,it3;
int arr[5010];


int main()
{
    int n,i,j,k;

    for(i=2;i<=38000;i++)
    {
        l.push_back(i);
    }
    int N=0;

    while(!l.empty()&&N!=3000)
    {
        arr[++N]=l.front();
        i=0;
        j=l.front();
        for(it1=l.begin();it1!=l.end();it1=it2)
        {
        	it2=it1;
                it2++;
            if(i%j==0)
            {

                l.erase(it1);
            }
            i++;
        }
    }

   /* for(i=0;i<10;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }*/


    scanf("%d",&n);

    while(n!=0)
    {
        printf("%d\n",arr[n]);

       scanf("%d",&n);
    }

    return 0;
}








