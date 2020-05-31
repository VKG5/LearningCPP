#include<iostream>
#include<vector>

// How to use pairs
/* pair <int, int> p1;

    p1.first = 10;
    p1.second = 20;

    cout<<p1.first<<" "<<p1.second; */

using namespace std;
#define nl "\n"
#define INT_MAX 99999999

void printMatrix(vector < vector <int> >, int);

void Floyd_Warshall(vector < vector <int> > adj, int V)
{
    vector < vector <int> > D(V, vector <int>(V));

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            D[i][j] = adj[i][j];

    // i - row, j - column
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(D[i][k]+D[k][j] < D[i][j])
                    D[i][j] = D[i][k]+D[k][j];
            }
        }
        // TO print all matrices starting from D1
        printMatrix(D, V);
        cout<<nl;
    }
}

void printMatrix(vector < vector <int> > D, int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(D[i][j]==INT_MAX)
                cout<<"INF"<<"\t";

            else
                cout<<D[i][j]<<"\t";
        }

        cout<<nl;
    }
}

int main()
{
    // Change according to needs
    // 0 - A, 1 - B, 2 - C, 3 - D
    // Input format (adj_mat, u, v, cost))

    int V = 5;
    vector < vector <int> > adj(V, vector <int>(V));

    // The D0 matrix
    adj = { {0, 3, INT_MAX, 5, 15},
            {6, 0, 11, 1, 2},
            {INT_MAX, INT_MAX, 0, 3, INT_MAX},
            {15, 9, 20, 0, 50},
            {1, 1, 1, 1, 0} };

    cout<<"\nThe all pair shortest path is: \n";
    Floyd_Warshall(adj, V);

    return 0;
}
