// Implementation of Kosaraju's algorithm to print all SCCs
#include<bits/stdc++.h>
using namespace std;
int memo[10010];
int path[10010];
int final_list[10010];
int PATH=-1,FINAL=-1,v,e;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing times)
    // The top element of stack has the maximum finishing time
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and prints strongly connected components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

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


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    //cout << v << " ";
    path[++PATH]=v;
    memo[v]=1;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v to Stack
    Stack.push(v);
}

// The main function that finds and prints all strongly connected components
void Graph::printSCCs()
{
    stack<int> Stack;
    int k,l,flag;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            PATH=-1;
            flag=0;

                memset(path,0,sizeof(path));

                memset(memo,0,sizeof(memo));
            gr.DFSUtil(v, visited);
            //cout << endl;

            for(k=0;k<=PATH;k++)
                {

                   /* for(l=0;l<v;l++)
                    {
                        if(arr[path[k]][l]&&memo[l]!=1)
                        {
                            flag=1;
                            break;
                        }
                    }*/
                    list<int>::iterator i;
                    for (i = adj[path[k]].begin(); i != adj[path[k]].end(); ++i)
                    {
                        if(memo[*i]!=1)
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

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
   /* Graph g(3);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 2);
    //g.addEdge(0, 3);
   // g.addEdge(3, 4);
   int v,e

    cout << "Following are strongly connected components in given graph \n";
    g.printSCCs();*/
    int i,j,st,ed;

    while(1)
    {
        FINAL=-1;
        memset(final_list,0,sizeof(final_list));
        cin>>v;
        if(v==0)
            break;
        cin>>e;
        Graph g(v);
        for(i=0;i<e;i++)
        {
            cin>>st;
            cin>>ed;
            //arr[st-1][ed-1]=1;
            g.addEdge(st-1,ed-1);
        }
        //scc();
        g.printSCCs();

        quicksort(0,FINAL);
        for(i=0;i<=FINAL;i++)
        {
            cout<<final_list[i]+1<<" ";
        }
        cout<<endl;
    }

    return 0;
}
