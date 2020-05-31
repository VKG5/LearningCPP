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
#define INF 99999999

char alphabet(int);

void addEdge(vector <intP> adj[], int u, int v, int wt)
{
    // To insert pair value in vector use {} per pair
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void primMST(vector <intP> adj[], int V)
{
    priority_queue < intP, vector <intP>, greater <intP> > pq;

    // Taking source vertex = 0
    int src = 0;

    // Vector for keys and initialize keys to INF
    vector <int> key(V, INF);

    // To store parent array
    // V - size, -1 - initial value
    vector <int> parent(V, -1);

    // To keep track of visited nodes
    vector <bool> visited(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    // Looping till empty
    while(!pq.empty())
    {
        // First vertex is the min key vertex
        // Vertex label is second of the pair

        int u = pq.top().second;
        pq.pop();

        visited[u]= true;

        for(auto x=adj[u].begin(); x!=adj[u].end(); x++)
        {
            // Get wt and label of current adjacent of u
            int v = (*x).first;
            int weight = (*x).second;

            if(visited[v] == false && key[v] > weight)
            {
                // Update key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for(int i=1; i<V; ++i)
    {
        cout<<alphabet(parent[i])<<" - "<<alphabet(i)<<"\n";
    }
}

// Modify according to your needs
char alphabet(int u)
{
    switch(u)
    {
        case 0: return 'Z';
                break;

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
    // Change according to needs
    // Z - 0, A-1 , B-2, C-3, D-4, E-5, F-6, G-7, H-8, I-9, J-10
    // Input format (adj_mat, u, v, cost))

    int V = 9;
    vector < intP > adj[V];

    // making above shown graph
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    cout<<"The edges included in MST are: \n";
    primMST(adj, V);

    return 0;
}
