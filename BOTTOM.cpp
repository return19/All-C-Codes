#include<bits/stdc++.h>
using namespace std;

int arr[10010][10010];
int arr_rev[10010][10010];
int visited[10010];
int v,e,PATH=-1,FINAL=-1;

int memo[10010];
int path[10010];
int final_list[10010];

void quicksort(int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(final_list[i]<=final_list[pivot]&&i<last)
                 i++;
             while(final_list[j]>final_list[pivot])
                 j--;
             if(i<j){
                 temp=final_list[i];
                  final_list[i]=final_list[j];
                  final_list[j]=temp;
             }
         }

         temp=final_list[pivot];
         final_list[pivot]=final_list[j];
         final_list[j]=temp;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}


stack<int> stk;
void dfs(int st)
{
    int i;
    visited[st]=1;
    path[++PATH]=st;
    memo[st]=1;
    //path[++PATH][0]=st;
    //cout<<st<<" ";
    for(i=1;i<v;i++)
    {
        /*if(arr[st][i]){
        path[++PATH][0]=st;
        path[++PATH][1]=i;
        }*/
        if(!visited[i]&&arr_rev[st][i])
            dfs(i);
    }
}

void reverse_graph()
{
    int i,j,temp;
    memset(arr_rev,0,sizeof(arr_rev));
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr_rev[j][i]=arr[i][j];
        }
    }

}

void make_stack(int st)
{
    int i;
    visited[st]=1;
    for(i=0;i<v;i++)
    {
        if(arr[st][i]&&!visited[i])
        {
            make_stack(i);
        }
    }
    stk.push(st);
}

void scc()
{
    int i,j,k,l,flag;
    memset(visited,0,sizeof(visited));
    for(i=0;i<v;i++)
    {
        if(!visited[i])
            make_stack(i);
    }
    reverse_graph();

    memset(visited,0,sizeof(visited));

    while(!stk.empty())
    {
        flag=0;
        i=stk.top();
        stk.pop();

        if(!visited[i])
            {
                PATH=-1;

                memset(path,0,sizeof(path));
                memset(memo,0,sizeof(memo));
                dfs(i);

                for(k=0;k<=PATH;k++)
                {

                    for(l=0;l<v;l++)
                    {
                        if(arr[path[k]][l]&&memo[l]!=1)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                        break;

                }
                if(flag==0)
                    {
                        for(k=0;k<=PATH;k++)
                            final_list[++FINAL]=path[k];
                    }
            }
    }
}

int main()
{
    int i,j,st,ed;

    while(1)
    {
        FINAL=-1;
        memset(final_list,0,sizeof(final_list));
        cin>>v;
        if(v==0)
            break;
        cin>>e;
        memset(arr,0,sizeof(arr));
        for(i=0;i<e;i++)
        {
            cin>>st;
            cin>>ed;
            arr[st-1][ed-1]=1;
        }
        scc();
        quicksort(0,FINAL);
        for(i=0;i<=FINAL;i++)
        {
            cout<<final_list[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
