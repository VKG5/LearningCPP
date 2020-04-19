#include<iostream>
#include<bits/stdc++.h>

// How to use pairs
/* pair <int, int> p1;

    p1.first = 10;
    p1.second = 20;

    cout<<p1.first<<" "<<p1.second; */

using namespace std;

// For making the edges of a pair
typedef pair <int, int> intP;
char alphabet(int);

struct Graph
{
    // V is the number of vertices, E is edges
    int V,E;

    // Sub-pair that is used for the vertices, and first element for cost
    vector < pair<int, intP> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void add_edge(int u, int v, int w)
    {
        // To insert pair value in vector use {} per pair
        edges.push_back({w, {u, v}});
    }

    // To return weight of MST
    int kruskalMST();
};

struct UnionFind
{
    int *parent, *rnk;

    UnionFind(int n)
    {
        parent = new int[n+1];
        rnk = new int[n+1];

        for(int i=0; i<n+1; i++)
        {
            // Initialize every rank to 0
            rnk[i] = 0;

            // Every element is parent of itself
            parent[i]=i;
        }
    }

    // Find parent node of 'u' node
    int find(int u)
    {
        if(u!=parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        // Make smaller component child of larger
        if(rnk[x]>rnk[y])
            parent[y] = x;

        else
            parent[x] = y;

        if(rnk[x] == rnk[y])
            rnk[y]++;
    }
};

// TODO
int Graph::kruskalMST()
{
    int mst_wt = 0;

    // Sorts according to first element, cost
    sort(edges.begin(), edges.end());

    UnionFind uf(V);

    for(auto it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int comp_u = uf.find(u);
        int comp_v = uf.find(v);

        // Check if the component of u and v is same or not
        if(comp_u != comp_v)
        {
            // If not same, current edge will be in MST
            cout<<alphabet(u)<<" - "<<alphabet(v)<<"\n";

            mst_wt += it->first;

            uf.merge(comp_u, comp_v);
        }
    }

    return mst_wt;
}

// Modify according to your needs
char alphabet(int u)
{
    switch(u)
    {
        case 1: return 'A';
                break;

        case 2: return 'B';
                break;

        case 3: return 'C';
                break;

        case 4: return 'D';
                break;

        case 5: return 'E';
                break;

        case 6: return 'F';
                break;

        case 7: return 'G';
                break;

        case 8: return 'H';
                break;

        case 9: return 'I';
                break;

        case 10: return 'J';
                 break;

        default: break;
    }
}

int main()
{
    int V=10, E=18;
    Graph g(V, E);

    // Change according to needs
    // A-1 , B-2, C-3, D-4, E-5, F-6, G-7, H-8, I-9, J-10
    // Input format ((u, v), cost))
    g.add_edge(1, 5, 1);
    g.add_edge(1, 2, 5);
    g.add_edge(1, 4, 9);
    g.add_edge(2, 3, 4);
    g.add_edge(2, 4, 2);
    g.add_edge(3, 10, 8);
    g.add_edge(3, 9, 1);
    g.add_edge(3, 8, 4);
    g.add_edge(4, 6, 5);
    g.add_edge(4, 5, 2);
    g.add_edge(4, 8, 2);
    g.add_edge(4, 7, 11);
    g.add_edge(5, 6, 1);
    g.add_edge(6, 7, 7);
    g.add_edge(7, 8, 1);
    g.add_edge(7, 9, 4);
    g.add_edge(8, 9, 6);
    g.add_edge(9, 10, 0);

    cout<<"The edges included in MST are: \n";
    int mst_wt = g.kruskalMST();

    cout<<"\nWeight of the MST: "<<mst_wt;

    return 0;
}
