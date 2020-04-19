// Reference - https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/?ref=rp
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V ;
    list < int > *adj;

public :

    Graph( int V )
    {
        this->V = V ;
        adj = new list<int>[V];
    }

    void addEdge (int s , int d)
    {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    bool BFS (int s ,int d);
};


bool Graph :: BFS(int s, int d)
{
    // Base case
    if (s == d)
        return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (*i == d)
                return true;

            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}

bool isSafe(int i, int j, vector < vector <int> > M, int N)
{
    if ((i < 0 || i >= N) || (j < 0 || j >= N ) || M[i][j] == 0)
        return false;
    return true;
}

bool findPath(vector < vector<int> > M, int N)
{
    int s , d ; // source and destination
    int V = N*N+2;
    Graph g(V);

    int k=1;
    for (int i =0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N; j++)
        {
            if (M[i][j] != 0)
            {
                if (isSafe( i , j+1 , M, N))
                    g.addEdge ( k , k+1 );
                if (isSafe( i , j-1 , M, N))
                    g.addEdge ( k , k-1 );
                if (j< N-1 && isSafe( i+1 , j , M, N))
                    g.addEdge ( k , k+N );
                if (i > 0 && isSafe( i-1 , j , M, N))
                    g.addEdge ( k , k-N );
            }

            // source index
            if( M[i][j] == 1 )
                s = k ;

            // destination index
            if (M[i][j] == 2)
                d = k;
            k++;
        }
    }

    return g.BFS (s, d) ;
}

int main()
{
    bool flag=true;
    int N;
    cin>>N;

    vector < vector<int> > M(N, vector <int>(N));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>M[i][j];


    flag = findPath(M, N);

    if(flag)
        cout<<"Yes\n";

    else
        cout<<"No\n";

    return 0;
}
