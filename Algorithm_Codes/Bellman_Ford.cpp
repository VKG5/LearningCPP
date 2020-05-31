#include<iostream>

using namespace std;

#define INF 99999999
#define nl "\n"

void print_arr(int [], int);

// Two structures for defining the graph
struct Edge
{
    int u;
    int v;
    int wt;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edge;

    // Array of edges for the graph
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        this->edge = new Edge[E];
    }
};

void Bellman_Ford(struct Graph *g, int source)
{
    int u, v, wt;

    int tot_V = g->V;

    int tot_E = g->E;

    // Distance Array
    int d[tot_V];

    // Predecessor Array
    int p[tot_V];

    for(int i=0; i<tot_V; i++)
    {
        d[i] = INF;
        p[i] = 0;
    }

    // Mark the source vertex
    d[source] = 0;

    // To relax edges |V-1| times
    for(int i=1; i<tot_V; i++)
    {
        for(int j=0; j<tot_E; j++)
        {
            u = g->edge[j].u;
            v = g->edge[j].v;
            wt = g->edge[j].wt;

            if((d[u]!=INF) && ((d[u]+wt)<d[v]))
            {
                d[v] = d[u] + wt;
                p[v] = u;
            }
        }
    }

    // Checking for negative cycle
    for(int i=0; i<tot_E; i++)
    {
        u = g->edge[i].u;
        v = g->edge[i].v;
        wt = g->edge[i].wt;

        if((d[u]!=INF) && ((d[u]+wt)<d[v]))
        {
            cout<<"Negative Cycle Detected!\n";
            return;
        }
    }

    // If no negative cycle, then return the distance
    cout<<"\nDistance Array: ";
    print_arr(d, tot_V);
    cout<<"\nPredecessor Array: ";
    print_arr(p, tot_E);
}

void print_arr(int arr[], int maxv)
{
    for(int i=0; i<maxv; i++)
        cout<<arr[i]<<" ";

    cout<<nl;
}

int main()
{
    struct Graph *g = new Graph(5, 6);

    // Inputting the graph
    // 1
    g->edge[0].u=0;
    g->edge[0].v=1;
    g->edge[0].wt=-1;

    // 2
    g->edge[1].u=0;
    g->edge[1].v=2;
    g->edge[1].wt=4;

    // 3
    g->edge[2].u=1;
    g->edge[2].v=2;
    g->edge[2].wt=3;

    // 4
    g->edge[3].u=2;
    g->edge[3].v=3;
    g->edge[3].wt=2;

    // 5
    g->edge[4].u=3;
    g->edge[4].v=4;
    g->edge[4].wt=-5;

    // 6
    g->edge[5].u=4;
    g->edge[5].v=2;
    g->edge[5].wt=2;

    // Passing the graph and the source node
    Bellman_Ford(g, 0);

    return 0;
}
