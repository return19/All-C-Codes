#include<bits/stdc++.h>
using namespace std;

int arr[10100];
int n;
vector< pair<int,int> > ans;

int pos[10100];
int taken[10100];

void swap_pos(int x,int y)
{
    swap(arr[x],arr[y]);
    pos[arr[x]]=x;
    pos[arr[y]]=y;

    x=arr[x];
    y=arr[y];

    swap(arr[x],arr[y]);
    pos[arr[x]]=x;
    pos[arr[y]]=y;

    /*swap(arr[arr[x]],arr[arr[y]]);

    pos[arr[arr[x]]]=arr[x];
    pos[arr[arr[y]]]=arr[y];*/
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        pos[arr[i]]=i;
    }

    for(i=1;i<n;i++)
    {
        if(taken[arr[i-1]])
            continue;
        else if(pos[i]==i-1){
            taken[i-1]=1;
        }
        else
        {
            int x=arr[pos[i]],idx=pos[i];
            int y=arr[i-1],idy=i-1;

            ans.push_back(make_pair(pos[i],i-1));
            swap_pos(pos[i],i-1);
            taken[i-1]=1;

            if(arr[idx]==x && arr[idy]==y)
                ans.pop_back();
        }

       /* for(j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<endl;

        for(j=0;j<n;j++)
            cout<<pos[j]<<" ";
        cout<<endl;*/
    }

    for(j=0;j<n;j++)
            cout<<arr[j]<<" ";
    cout<<endl;

    printf("%d\n",ans.size());

    for(i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }

    return 0;
}

