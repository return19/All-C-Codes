#include<bits/stdc++.h>
using namespace std;

typedef struct a
{
    int st;
    int ed;

}elem;

elem arr[101000];

int cmp(elem a,elem b)
{
    if(a.ed==b.ed)
        return a.st<b.st;

    return a.ed<b.ed;
}

int main()
{
    int i,j,k;
    int n;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i].st;
        cin>>arr[i].ed;
    }

    sort(arr,arr+n,cmp);

    int p_ed=arr[0].ed;

    cout<<arr[0].st<<" "<<arr[0].ed<<endl;

    for(i=1;i<n;i++)
    {
        if(arr[i].st<p_ed)
            continue;

        cout<<arr[i].st<<" "<<arr[i].ed<<endl;

        p_ed=arr[i].ed;
    }


    return 0;
}






