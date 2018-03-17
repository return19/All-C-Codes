#include<stdio.h>

typedef struct ll
{
    int u;
    int v;
    int w;
}edge1;

int ne;
edge1 edge[100000];


/*void change(int start,int end)
{
    int sum;
    for(i=0;i<ne;i++)
    {

        if(edge[i].u==start)
            break;
    }
    if(edge[i].v==end)
    {
        sum=sum+edge[i].w;

        return;
    }
    else
    {
        sum=sum+edge[i].w+traverse(edge[i].v,end);
        /*arr[start][0]=end;
        arr[start][1]=sum;
        return;
    }

}*/

int traverse(int start,int end)
{
    int sum=0,i;
    /*if(arr[start][1]!=0&&arr[start][0]==end)
    {
        return arr[start][1];
    }*/
    for(i=0;i<ne-1;i++)
    {

        if(edge[i].u==start)
            break;
    }
    if(edge[i].v==end)
    {

        return edge[i].w;
    }
    else
    {
        sum=sum+edge[i].w+traverse(edge[i].v,end);
        //arr[start][0]=end;
        //arr[start][1]=sum;
        return sum;
    }

}

int main()
{

    int i,ne,q,type,s,e;
    scanf("%d",&ne);

    for(i=0;i<ne-1;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    scanf("%d",&q);

for(i=0;i<q;i++)
{
        scanf("%d",&type);
        scanf("%d%d",&s,&e);

    if(type==1)
    {
        edge[s].w=e;

    }
    else
    {
        printf("%d\n",traverse(s,e));
    }
}


    return 0;
}










